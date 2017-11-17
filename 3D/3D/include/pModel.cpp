#include "pModel.h"

PModel::PModel() : _currFile(NULL)
{
	_fileFactory = new FileFactory<PointT>();
	_grabberNotify = new GrabberNotify(this);
	_grabberFactory = new GrabberFactory<PointT>(_grabberNotify);
}

void PModel::SetViewerNotify(ViewerNotify* viewerNotify)
{
	_viewerNotify = viewerNotify;
}

void PModel::Open3DFile(std::string dir, std::string filter)
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
	_viewerNotify->UpdateFileNotify();
}

boost::shared_ptr<pcl::PointCloud<PointT>> PModel::GetFilePointCloud()
{
	return _currFile->GetPointCloud();
}

//				Grabber
void PModel::OpenRSGrabber()
{
	_currGrabber = _grabberFactory->GetRSGrabber();
	_currGrabber->OpenGrabber();
}

void PModel::UpdateNewCloudNotify()
{
	_viewerNotify->UpdateGrabberNotify();
}

boost::shared_ptr<pcl::PointCloud<PointT>> PModel::GetGrabberPointCloud()
{
	return _currGrabber->GetPointCloud();
}