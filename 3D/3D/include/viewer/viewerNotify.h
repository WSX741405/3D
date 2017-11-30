#ifndef VIEW_NOTIFY
#define VIEW_NOTIFY

#include "ui/mainWindow.h"

class MainWindow;

class ViewerNotify
{
public:
	ViewerNotify()
	{
	}

	void Attach(MainWindow* window);
	void UpdatePointCloudNotify();

private:
	MainWindow* _window;
};

#endif