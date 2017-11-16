#include <QtWidgets/QApplication>
#include <pcl/io/io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include "ui/mainWindow.h"
#include "pModel.h"

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);
	MainWindow window(new PModel());
	window.show();
	return application.exec();
}