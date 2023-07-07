#include "KFileEdtitor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KFileEdtitor w;
    w.show();
    return a.exec();
}
