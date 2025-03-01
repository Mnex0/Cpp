#ifndef CONTACTDIALOG_H
#define CONTACTDIALOG_H

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QAction>
#include <QPushButton>
#include <QGridLayout>
#include <QString>
#include <QMessageBox>

class ContactDialog : public QDialog
{
    Q_OBJECT
    public:
        ContactDialog(QWidget* parent=nullptr);
        virtual ~ContactDialog(){};

        pair<QString,int> getData();
        void setData(const pair<QString,int> &tuple);
        void setMode(bool mode);
        void clear();

    public slots:
        void slotOk();

    private:
        QLabel* name;
        QLabel* num;
        QLineEdit* editname;
        QLineEdit* editnum;
        bool mode_edit;
        QPushButton* btnOK;
        QPushButton* btnCl;
};

#endif