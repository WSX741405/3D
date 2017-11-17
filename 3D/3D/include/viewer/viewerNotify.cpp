#include "viewer/viewerNotify.h"

void ViewerNotify::Attach(MainWindow* window)
{
	_window = window;
}

void ViewerNotify::UpdateFileNotify()
{
	_window->ShowFilePointCloud();
}

void ViewerNotify::UpdateGrabberNotify()
{
	_window->ShowGrabberPointCloud();
}