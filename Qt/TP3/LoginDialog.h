#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <QDialog>
#include <QLabel>
#include <QPushButton>

class LoginDialog : public QDialog
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
        QLabel*
};

#endif