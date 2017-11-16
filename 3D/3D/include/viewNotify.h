#ifndef VIEW_NOTIFY
#define VIEW_NOTIFY

#include "ui_mainwindow.h"
#include "ui/mainWindow.h"

class ViewNotify
{
public:
	ViewNotify()
	{
	}

	void Attach(MainWindow* window)
	{
		_window = window;
	}

	void UpdateViewerNotify()
	{
		_window->UpdateViewer();
	}

private:
	MainWindow* _window;
};

#endif