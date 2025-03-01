#include "MyWindow.h"

MyWindow::MyWindow(QMainWindow* parent): QMainWindow(parent)
{    
    this->setMinimumWidth(500);
    QWidget* widget_central = new QWidget;
    this->setCentralWidget(widget_central);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* hlayout = new QHBoxLayout;

    QMenu *fileMenu;
    fileMenu = menuBar()->addMenu(tr("&Fichier"));
    QAction* closeAct = new QAction(tr("&Quitter"), this);
    fileMenu->addAction(closeAct);
    connect(closeAct, &QAction::triggered, qApp, QApplication::quit);

//--Button
    this->button1 = new QPushButton("My first button");
    hlayout->addWidget(button1);
    connect(button1, &QPushButton::clicked, this, &MyWindow::slot_button1);

//--Button1
    this->button2 = new QPushButton("A second button");
    hlayout->addWidget(button2);
    connect(button2, &QPushButton::clicked, this, &MyWindow::slot_button2);

    this->textedit = new QTextEdit();
    this->textedit->setText("Bonjour !");
    mainLayout->addWidget(textedit);

    mainLayout->addLayout(hlayout);
    widget_central->setLayout(mainLayout);
}

void MyWindow::slot_button1()
{
    this->textedit->setText("Bravo");
    QMessageBox::information(this, "info", "Bravo", QMessageBox::Ok);
}

void MyWindow::slot_button2()
{
    int result = dialog.exec();
    qDebug() << result;
}