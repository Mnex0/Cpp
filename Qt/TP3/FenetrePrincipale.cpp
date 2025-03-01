#include "FenetrePrincipale.h"

using namespace std;

FenetrePrincipale::FenetrePrincipale(QMainWindow* parent): QMainWindow(parent)
{    
    this->setMinimumWidth(500);
    QWidget* widget_central = new QWidget;
    this->setCentralWidget(widget_central);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* hlayout = new QHBoxLayout;

    QMenu *fileMenu;
    fileMenu = menuBar()->addMenu(tr("&Fichier"));
    QAction* closeAct = new QAction(tr("&Quitter"), this);
    connect(closeAct, &QAction::triggered, qApp, QApplication::quit);
    QAction* saveAct = new QAction(tr("&Enregistrer"),this);
    connect(saveAct, &QAction::triggered, this, &FenetrePrincipale::slotEnregistrer);
    QAction* openAct = new QAction(tr("&Ouvrir"), this);
    connect(openAct, &QAction::triggered, this, &FenetrePrincipale::slotOuvrir);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(closeAct);

//--ButtonAdd
    this->buttonAdd = new QPushButton("+");
    hlayout->addWidget(buttonAdd);
    connect(buttonAdd, &QPushButton::clicked, this, &FenetrePrincipale::slot_buttonAdd);

//--Field
    this->lineEdit = new QLineEdit("Chercher un contact");
    hlayout->addWidget(lineEdit);

//--ButtonSearch
    this->buttonSearch = new QPushButton();
    buttonSearch->setIcon(QIcon("loupe.png"));
    hlayout->addWidget(buttonSearch);
    connect(buttonSearch, &QPushButton::clicked, this, &FenetrePrincipale::slot_buttonSearch);

//--QListWidget
    this->list = new QListWidget;
    list->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(list, &QWidget::customContextMenuRequested, this, &FenetrePrincipale::slotCustomMenuRequested);
    mainLayout->addLayout(hlayout);
    mainLayout->addWidget(list);
    widget_central->setLayout(mainLayout);
}
void FenetrePrincipale::slot_buttonAdd()
{
    dialog.setMode(true);
    if(dialog.exec() == QDialog::Accepted) 
    {
        auto data = dialog.getData();
        dialog.clear();
        qDebug() << "Nom : " << data.first << "Num : " << data.second;
        contacts.insert({data.first, data.second});
        list->addItem(data.first);  // Ajoute le contact UNIQUEMENT si "OK" a été pressé
    }
}

void FenetrePrincipale::slot_buttonSearch()
{
    QString contact = this->lineEdit->text();
    QListWidgetItem* item = list->item(0);
    for(int i = 0; i < list->count(); ++i)
    {
        item = list->item(i);
        if(item->text() == contact)
        {
            break;
        }
    }
    if(item->text() == contact)
    {
        dialog.setMode(false);
        dialog.setData({contact,contacts[contact]});
        dialog.exec();
        dialog.clear();
    }
    else
    {
        QMessageBox::warning(this, "Erreur","Ce contact n'éxiste pas.");
    }
}

void FenetrePrincipale::slotCustomMenuRequested(const QPoint &pos)
{
    // Vérifie si un item est sélectionné
    if (!list->currentItem())
    {
        return; // Aucun élément sélectionné => on ne fait rien
    }

    // Création du menu contextuel
    QMenu menu(this);

    QAction *actionAfficher = new QAction("Afficher", &menu);
    QAction *actionEditer = new QAction("Éditer", &menu);
    QAction *actionSupprimer = new QAction("Supprimer", &menu);

    menu.addAction(actionAfficher);
    menu.addAction(actionEditer);
    menu.addAction(actionSupprimer);

    // Connexion des actions aux slots correspondants
    connect(actionAfficher, &QAction::triggered, this, &FenetrePrincipale::slot_afficher);
    connect(actionEditer, &QAction::triggered, this, &FenetrePrincipale::slot_editer);
    connect(actionSupprimer, &QAction::triggered, this, &FenetrePrincipale::slot_supprimer);

    // Affiche le menu contextuel à la position du clic
    menu.exec(list->viewport()->mapToGlobal(pos));
}

void FenetrePrincipale::slot_afficher()
{
    auto currentItem = list->currentItem();
    if (!currentItem) return;

    QString nom = currentItem->text();

    if (contacts.find(nom) != contacts.end()) {
        dialog.setMode(false); // Mode affichage
        dialog.setData({nom, contacts[nom]});
        dialog.exec();
    }
}

void FenetrePrincipale::slot_editer()
{
    auto currentItem = list->currentItem();
    if (!currentItem) return;

    QString ancienNom = currentItem->text();

    if (contacts.find(ancienNom) != contacts.end()) {
        dialog.setMode(true); // Mode édition
        dialog.setData({ancienNom, contacts[ancienNom]});

        if (dialog.exec() == QDialog::Accepted) {
            auto newData = dialog.getData();
            dialog.clear();

            // Si le nom a changé
            if (newData.first != ancienNom) {
                if (contacts.find(newData.first) != contacts.end()) {
                    QMessageBox::warning(this, "Erreur", "Ce nom existe déjà !");
                    return;
                }

                // Supprimer l'ancien et ajouter le nouveau
                contacts.erase(ancienNom);
                contacts[newData.first] = newData.second;

                currentItem->setText(newData.first); // Mettre à jour la liste
            } else {
                // Mise à jour du numéro uniquement
                contacts[ancienNom] = newData.second;
            }
        }
    }
}

void FenetrePrincipale::slot_supprimer()
{
    auto currentItem = list->currentItem();
    if (!currentItem) return;

    QString nom = currentItem->text();

    // Confirmation avant la suppression
    if (QMessageBox::question(this, "Confirmation", "Supprimer ce contact ?") == QMessageBox::Yes) 
    {
        contacts.erase(nom); // Supprimer du tableau associatif
        delete list->takeItem(list->row(currentItem)); // Supprimer de l'affichage
    }
}

void FenetrePrincipale::slotOuvrir()
{
    QString nomfic = QFileDialog::getOpenFileName(this, "Fichier contacts", ".", "*.txt");
    if (!nomfic.isEmpty()) 
    {
        lireFic(nomfic);
    }
}

void FenetrePrincipale::slotEnregistrer()
{
    QString nomfic = QFileDialog::getSaveFileName(this, "Enregistrer les contacts", ".", "*.txt");
    if (!nomfic.isEmpty()) 
    {
        ecrireFic(nomfic);
    }
}

void FenetrePrincipale::lireFic(QString nomfic)
{
    QFile fichier(nomfic);
    if (!fichier.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier.");
        return;
    }

    contacts.clear();
    list->clear();

    QTextStream in(&fichier);
    while (!in.atEnd()) 
    {
        QString ligne = in.readLine();
        QStringList elements = ligne.split(";");
        if (elements.size() == 2) 
        {
            QString nom = elements[0];
            int numero = elements[1].toInt();
            contacts[nom] = numero;
            list->addItem(nom);
        }
    }

    fichier.close();
}

void FenetrePrincipale::ecrireFic(QString nomfic)
{
    QFile fichier(nomfic);
    if (!fichier.open(QIODevice::WriteOnly | QIODevice::Text)) 
    {
        QMessageBox::critical(this, "Erreur", "Impossible de créer le fichier.");
        return;
    }

    QTextStream out(&fichier);
    for (const auto &contact : contacts) 
    {
        out << contact.first << ";" << contact.second << "\n";
    }

    fichier.close();
}

void FenetrePrincipale::addItem(QString contact)
{
    list->addItem(contact);
}
