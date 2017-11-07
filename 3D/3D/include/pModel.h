#ifndef P_MODEL
#define P_MODEL

#include "file/fileFactory.h"
#include "viewer/viewer.h"

class PModel
{
public:
	PModel()
	{
	}
	/*
	std::string dir = std::string("3DFace/head3d.obj");
	FileFactory<PointT>* fileFactory = new FileFactory<PointT>();
	ThreeDFile<PointT>* file = fileFactory->GetObjFile(dir);
	file->LoadFile();
	Viewer<PointT>* viewer = new Viewer<PointT>();
	viewer->Show(file->GetCloud());
	*/
};

#endif