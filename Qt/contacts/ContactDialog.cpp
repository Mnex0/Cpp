#include "ContactDialog.h"
using namespace std;

ContactDialog::ContactDialog(QWidget* parent): QDialog(parent)
{
    this->setWindowTitle("My Dialog");
    this->setMinimumWidth(500);

    QGridLayout* glayout = new QGridLayout;

    this->name = new QLabel("Name");
    glayout->addWidget(name,0,0);

    this->num = new QLabel("Numéro");
    glayout->addWidget(num,1,0);

    this->editname = new QLineEdit();
    this->editname->clear();
    glayout->addWidget(editname,0,1);

    this->editnum = new QLineEdit();
    this->editnum->clear();
    glayout->addWidget(editnum,1,1);

    this->btnOK = new QPushButton("OK");
    glayout->addWidget(btnOK,2,0);
    connect(btnOK, &QPushButton::clicked, this, &ContactDialog::slotOk);

    this->btnCl = new QPushButton("Cancel");
    glayout->addWidget(btnCl,2,1);
    connect(btnCl, &QPushButton::clicked, this, &ContactDialog::reject);

    this->setLayout(glayout);
}

pair<QString,int> ContactDialog::getData()
{
    return {this->editname->text(), this->editnum->text().toInt()};
}
void ContactDialog::setData(const pair<QString,int> &tuple)
{
    this->editname->setText(tuple.first);
    this->editnum->setText(QString::number(tuple.second));
}
void ContactDialog::setMode(bool mode)
{
    this->mode_edit = mode;
}

void ContactDialog::clear()
{
    this->editname->clear();
    this->editnum->clear();
}

void ContactDialog::slotOk()
{
    QString msg{""};
    bool ok;

    // Vérification des champs
    if (this->editname->text().isEmpty() || this->editnum->text().isEmpty())
    {
        if (this->editname->text().isEmpty())
        {
            msg = "Name cannot be empty.";
        }
        else
        {
            msg = "Number cannot be empty.";
        }
    }
    else 
    {
        // Vérification si le numéro est bien un entier
        this->editnum->text().toInt(&ok);
        if (!ok)
        {
            msg = "Number is not an int.";
        }
    }

    // Si une erreur est détectée, on affiche l'erreur et on empêche la validation
    if (!msg.isEmpty()) 
    {
        QMessageBox::critical(this, "Erreur", msg);
        return;  //Quitte immédiatement la fonction pour éviter accept()
    }
    accept();  //Seulement si tout est valide
}
