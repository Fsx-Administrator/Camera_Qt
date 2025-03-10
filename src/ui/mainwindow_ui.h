#pragma once

#include "maintoolbar.h"


class MainWindow;

class MainWindow_Ui
{

public:
    explicit MainWindow_Ui(MainWindow *parent);
    ~MainWindow_Ui() noexcept = default;

    MainToolBar *mainToolBar;

};
