#include <QtWidgets/QApplication>
#include <pcl/io/io.h>

#include "ui/mainWindow.h"
#include "pModel.h"

int main(int argc, char *argv[])
{
	PModel* pModel = new PModel();
	QApplication application(argc, argv);
	MainWindow window(pModel);
	window.show();
	return application.exec();
}