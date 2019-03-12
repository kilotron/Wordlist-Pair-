#include "WordlistGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WordlistGUI w;
	w.show();
	return a.exec();
}
