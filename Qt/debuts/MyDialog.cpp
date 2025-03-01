#include "MyDialog.h"

MyDialog::MyDialog(QWidget* parent): QDialog(parent)
{
    this->setWindowTitle("My Dialog");
    this->setMinimumWidth(500);

    QGridLayout* glayout = new QGridLayout;

    this->label1 = new QLabel("Label 1");
    glayout->addWidget(label1,0,0);

    this->label2 = new QLabel("Label 2");
    glayout->addWidget(label2,1,0);

    this->edit1 = new QLineEdit();
    glayout->addWidget(edit1,0,1);

    this->edit2 = new QLineEdit();
    glayout->addWidget(edit2,1,1);

    this->btnOK = new QPushButton("OK");
    glayout->addWidget(btnOK);
    connect(btnOK, &QPushButton::clicked, this, &MyDialog::accept);

    this->btnCl = new QPushButton("Cancel");
    glayout->addWidget(btnCl);
    connect(btnCl, &QPushButton::clicked, this, &MyDialog::reject);

    this->setLayout(glayout);
}