#include "pModel.h"
#include "grabberNotify.h"

void GrabberNotify::NotifyNewCloudArrived()
{
	_pModel->UpdateNewCloudNotify();
}