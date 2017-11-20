#include "pModel.h"

PModel::PModel() : _currFile(NULL)
{
	_fileFactory = new FileFactory<PointT>();
	_grabberNotify = new GrabberNotify(this);
	_grabberFactory = new GrabberFactory<PointT>(_grabberNotify);
	_arduino = new Tserial();
	if (_arduino != 0)
		_arduino->connect("COM4", 9600, spNONE);
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

void PModel::MotorTurnLeft(int distance)
{
	//			0    Turn Left
	unsigned char dir = '0' & 0xff;;
	unsigned char dis = (distance + '0') & 0xff;;
	_arduino->sendChar(dir);
	_arduino->sendChar(dis);
}

void PModel::MotorTurnRight(int distance)
{
	//			1    Turn Right
	unsigned char dir = '1' & 0xff;;
	unsigned char dis = (distance + '0') & 0xff;;
	_arduino->sendChar(dir);
	_arduino->sendChar(dis);
}