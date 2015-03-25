#include "EyeLeoX.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	EyeLeoX w;
	w.show();
	return a.exec();
}
