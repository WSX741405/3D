#include "ui/mainwindow.h"
#include "file/fileFactory.h"
#include "viewer/viewer.h"

#include <QtWidgets/QApplication>
#include <pcl/io/io.h>

typedef pcl::PointXYZ PointT;

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);
	mainWindow window;
	window.show();

	/*
	std::string dir = std::string("3DFace/head3d.obj");
	FileFactory<PointT>* fileFactory = new FileFactory<PointT>();
	ThreeDFile<PointT>* file = fileFactory->GetObjFile(dir);
	file->LoadFile();
	Viewer<PointT>* viewer = new Viewer<PointT>();
	viewer->Show(file->GetCloud());
	*/
	return application.exec();
}