#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "pModel.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(PModel* pModel, QWidget* parent = 0);
	~MainWindow();

public slots:
	void Open3DFileDialogSlot();

private:

	Ui::_mainWindow* _ui;
	PModel* _pModel;
};

#endif 
