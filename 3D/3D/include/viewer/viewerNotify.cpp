#include "viewer/viewerNotify.h"

void ViewerNotify::Attach(MainWindow* window)
{
	_window = window;
}

void ViewerNotify::UpdatePointCloudNotify()
{
	_window->UpdatePointCloudTable();
	_window->UpdateVTKViewer();
}