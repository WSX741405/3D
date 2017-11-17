#include <QtWidgets/QApplication>
#include <pcl/io/io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include "ui/mainWindow.h"
#include "pModel.h"
#include "viewer/viewerNotify.h"

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);
	ViewerNotify* viewerNotify = new ViewerNotify();
	MainWindow window(new PModel(), viewerNotify);
	window.show();
	return application.exec();
}