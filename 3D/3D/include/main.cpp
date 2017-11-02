#include <pcl/io/io.h>
#include "file/fileFactory.h"
#include "viewer/viewer.h"

typedef pcl::PointXYZ PointT;

int main()
{
	std::string dir = std::string("3DFace/head3d.obj");
	FileFactory<PointT>* fileFactory = new FileFactory<PointT>();
	ThreeDFile<PointT>* file = fileFactory->GetObjFile(dir);
	file->LoadFile();
	Viewer<PointT>* viewer = new Viewer<PointT>();
	viewer->Show(file->GetCloud());

	return 0;
}