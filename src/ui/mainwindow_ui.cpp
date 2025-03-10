#include "mainwindow_ui.h"

#include "camera.h"
#include "mainwindow.h"

MainWindow_Ui::MainWindow_Ui(MainWindow *parent)
    : mainToolBar(new MainToolBar(parent))
{
    parent->addToolBar(mainToolBar);
    parent->setCentralWidget(Camera::instance().widget());
}
