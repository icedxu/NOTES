#include "customtitle.h"
#include <QtWidgets/QApplication>
#include "nofocuswidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	NoFocusWidget w;
	w.show();
	return a.exec();
}
