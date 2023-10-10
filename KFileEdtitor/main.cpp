#include "KFileEdtitor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KFileEdtitor w;

	QIcon icon("./images/logo.ico");
	a.setWindowIcon(icon);

	QString qssFile = QString("./qss/Style.css");
	QFile styleFile(qssFile);
	if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream styleStream(&styleFile);
		QString style = styleStream.readAll();
		w.setStyleSheet(style);
		styleFile.close();
	}
    w.show();
    return a.exec();
}
