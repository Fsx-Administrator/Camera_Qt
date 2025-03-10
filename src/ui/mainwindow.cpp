#include "mainwindow.h"
#include "mainwindow_ui.h"

#include "camera.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new MainWindow_Ui(this))
{
    Camera::instance().start();
}

MainWindow::~MainWindow()
{
    Camera::instance().stop();
    delete ui;
}
