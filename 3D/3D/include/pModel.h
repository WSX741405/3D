#ifndef P_MODEL
#define P_MODEL

#include "file/fileFactory.h"
#include "viewer/viewer.h"

typedef pcl::PointXYZRGB PointT;

class PModel
{
public:
	PModel() : _currFile(NULL)
	{
		_fileFactory = new FileFactory<PointT>();
		_viewer = new Viewer<PointT>();
	}

	//				File
	void Open3DFile(std::string dir, std::string filter)
	{
		if (filter == std::string("OBJ(*.obj)"))
		{
			_currFile = _fileFactory->GetObjFile(dir);
		}
		else if(filter == std::string("PLY(*.ply)"))
		{
			_currFile = _fileFactory->GetPlyFile(dir);
		}
		_currFile->LoadFile();
		_viewer->Show(_currFile->GetCloud());
	}

	//				Viewer
	void ClearViewer()
	{
		_viewer->Clear();
	}

private:
	FileFactory<PointT>* _fileFactory;
	ThreeDFile<PointT>* _currFile;
	Viewer<PointT>* _viewer;
};

#endif