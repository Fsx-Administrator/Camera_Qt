#pragma once

#include <QMainWindow>


class MainWindow_Ui;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MainWindow_Ui *ui;

};
