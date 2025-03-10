#pragma once

#include <QToolBar>


class CameraNamesComboBox;
class CameraFormatsComboBox;
class QActionGroup;

class MainToolBar final : public QToolBar
{
    Q_OBJECT

public:
    explicit MainToolBar(QWidget *parent = nullptr) noexcept;
    ~MainToolBar() noexcept = default;

private:
    CameraNamesComboBox *cameraNamesComboBox_;
    CameraFormatsComboBox *cameraResolutionComboBox_;
    QActionGroup *actions_;

};
