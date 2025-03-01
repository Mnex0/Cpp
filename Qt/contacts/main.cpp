#include "FenetrePrincipale.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    FenetrePrincipale window;
    window.show();
    return app.exec();
}