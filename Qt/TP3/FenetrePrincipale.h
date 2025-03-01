#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <stdexcept>
#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <map>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QIcon>
#include <QTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <fstream>


class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT
    public:
        FenetrePrincipale(QMainWindow* parent=nullptr);
        virtual ~FenetrePrincipale(){};
        void addItem(QString contact);
        void lireFic(QString nomfic);
        void ecrireFic(QString nomfic);

    public slots:
        void slot_buttonAdd();
        void slot_buttonSearch();
        void slotEnregistrer();
        void slotOuvrir();
        void slotCustomMenuRequested(const QPoint &pos);
        void slot_afficher();
        void slot_editer();
        void slot_supprimer();

    private:
        QPushButton* buttonAdd;
        QPushButton* buttonSearch;
        QLineEdit* lineEdit;
        QListWidget* list;
        ContactDialog dialog{this};
        map<QString,int> contacts;
};

#endif