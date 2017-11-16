#ifndef P_MODEL
#define P_MODEL

#include <chrono>
#include <thread>

#include "file/fileFactory.h"
#include "grabber/grabberNotify.h"
#include "grabber/grabberFactory.h"
#include "viewer/viewer.h"

typedef pcl::PointXYZRGBA PointT;

class PModel
{
public:
	PModel() : _currFile(NULL)
	{
		_fileFactory = new FileFactory<PointT>();
		_grabberNotify = new GrabberNotify(this);
		_grabberFactory = new GrabberFactory<PointT>(_grabberNotify);
		//_viewer = new Viewer<PointT>();
	}

	void ClearViewer()
	{

	}

	//				File
	void Open3DFile(std::string dir, std::string filter)
	{
		if (filter == std::string("OBJ(*.obj)"))
		{
			_currFile = _fileFactory->GetObjFile(dir);
		}
		else if (filter == std::string("PLY(*.ply)"))
		{
			_currFile = _fileFactory->GetPlyFile(dir);
		}
		_currFile->LoadFile();

		//_viewer->Show(_currFile->GetCloud());
	}

	//				Grabber
	void OpenRSGrabber()
	{
		_currGrabber = _grabberFactory->GetRSGrabber();
		_currGrabber->OpenGrabber();
	}

	void UpdateNewCloudNotify()
	{
		_currGrabber->UnlockMutex();
	}

private:
	FileFactory<PointT>* _fileFactory;
	GrabberFactory<PointT>* _grabberFactory;
	GrabberNotify* _grabberNotify;
	ThreeDFile<PointT>* _currFile;
	Grabber<PointT>* _currGrabber;
};

#endif