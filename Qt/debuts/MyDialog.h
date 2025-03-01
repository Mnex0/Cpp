#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QTextEdit>
#include <QAction>

class MyDialog : public QDialog
{
    Q_OBJECT
    public:
    MyDialog(QWidget* parent=nullptr);
    virtual ~MyDialog(){};

    private:
        QLabel* label1;
        QLabel* label2;
        QLineEdit* edit1;
        QLineEdit* edit2;
        QPushButton* btnOK;
        QPushButton* btnCl;
};

#endif