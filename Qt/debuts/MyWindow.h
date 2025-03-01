#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMenu>
#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>

#include "MyDialog.h"


class MyWindow : public QMainWindow
{
    Q_OBJECT
    public:
        MyWindow(QMainWindow* parent=nullptr);
        virtual ~MyWindow(){};

    public slots:
        void slot_button1();
        void slot_button2();

    private:
        QPushButton* button1;
        QPushButton* button2;
        QTextEdit* textedit;
        MyDialog dialog{this};
};

#endif