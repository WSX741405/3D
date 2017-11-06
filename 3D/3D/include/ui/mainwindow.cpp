#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::_mainWindow())
{
	ui->setupUi(this);
	//	event
	//connect(ui->_open3DFileBtn, SIGNAL(clicked()), this, SLOT();
}

mainWindow::~mainWindow()
{

}