/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui__mainWindow
{
public:
    QAction *_openFileMenu;
    QAction *_openRSMenu;
    QAction *_motorTurnLeftMenu;
    QAction *MotorTurnRightMenu;
    QWidget *centralWidget;
    QPushButton *_motorTurnLeftBtn;
    QPushButton *_motorTurnRightBtn;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuGrabber;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *_mainWindow)
    {
        if (_mainWindow->objectName().isEmpty())
            _mainWindow->setObjectName(QStringLiteral("_mainWindow"));
        _mainWindow->resize(900, 690);
        _openFileMenu = new QAction(_mainWindow);
        _openFileMenu->setObjectName(QStringLiteral("_openFileMenu"));
        _openRSMenu = new QAction(_mainWindow);
        _openRSMenu->setObjectName(QStringLiteral("_openRSMenu"));
        _motorTurnLeftMenu = new QAction(_mainWindow);
        _motorTurnLeftMenu->setObjectName(QStringLiteral("_motorTurnLeftMenu"));
        MotorTurnRightMenu = new QAction(_mainWindow);
        MotorTurnRightMenu->setObjectName(QStringLiteral("MotorTurnRightMenu"));
        centralWidget = new QWidget(_mainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        _motorTurnLeftBtn = new QPushButton(centralWidget);
        _motorTurnLeftBtn->setObjectName(QStringLiteral("_motorTurnLeftBtn"));
        _motorTurnLeftBtn->setGeometry(QRect(40, 600, 75, 30));
        _motorTurnRightBtn = new QPushButton(centralWidget);
        _motorTurnRightBtn->setObjectName(QStringLiteral("_motorTurnRightBtn"));
        _motorTurnRightBtn->setGeometry(QRect(150, 600, 75, 30));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(600, 30, 260, 200));
        _mainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(_mainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuGrabber = new QMenu(menuBar);
        menuGrabber->setObjectName(QStringLiteral("menuGrabber"));
        _mainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(_mainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        _mainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(_mainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        _mainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuGrabber->menuAction());
        menuFile->addAction(_openFileMenu);
        menuGrabber->addAction(_openRSMenu);

        retranslateUi(_mainWindow);

        QMetaObject::connectSlotsByName(_mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *_mainWindow)
    {
        _mainWindow->setWindowTitle(QApplication::translate("_mainWindow", "mainWindow", Q_NULLPTR));
        _openFileMenu->setText(QApplication::translate("_mainWindow", "Open File", Q_NULLPTR));
        _openRSMenu->setText(QApplication::translate("_mainWindow", "RS Get One Frame", Q_NULLPTR));
        _motorTurnLeftMenu->setText(QApplication::translate("_mainWindow", "Motor Turn Left", Q_NULLPTR));
        MotorTurnRightMenu->setText(QApplication::translate("_mainWindow", "Motor Turn Right", Q_NULLPTR));
        _motorTurnLeftBtn->setText(QApplication::translate("_mainWindow", "Turn Left", Q_NULLPTR));
        _motorTurnRightBtn->setText(QApplication::translate("_mainWindow", "Turn Right", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("_mainWindow", "File", Q_NULLPTR));
        menuGrabber->setTitle(QApplication::translate("_mainWindow", "Grabber", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class _mainWindow: public Ui__mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
