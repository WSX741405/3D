#include <QtWidgets/QApplication>
#include <pcl/io/io.h>

#include "ui/mainWindow.h"
#include "pModel.h"

typedef pcl::PointXYZ PointT;

int main(int argc, char *argv[])
{
	PModel* pModel = new PModel();
	QApplication application(argc, argv);
	MainWindow window(pModel);
	window.show();
	return application.exec();
}