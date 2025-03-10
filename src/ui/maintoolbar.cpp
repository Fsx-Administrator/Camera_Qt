#include "maintoolbar.h"

#include "camera.h"
#include "cameranamescombobox.h"
#include "cameraformatscombobox.h"

#include <QActionGroup>


MainToolBar::MainToolBar(QWidget *parent) noexcept
    : QToolBar(parent)
    , cameraNamesComboBox_(new CameraNamesComboBox(this))
    , cameraResolutionComboBox_(new CameraFormatsComboBox(this))
    , actions_(new QActionGroup(this))
{
    addWidget(cameraNamesComboBox_);
    addWidget(cameraResolutionComboBox_);

    setIconSize(QSize(32, 32));

    connect(
        actions_->addAction(new QAction(QIcon(":/icons/record.png"), QString(), this)),
        &QAction::triggered,
        &Camera::instance(),
        &Camera::startRecord
    );
    connect(
        actions_->addAction(new QAction(QIcon(":/icons/stop_record.png"), QString(), this)),
        &QAction::triggered,
        &Camera::instance(),
        &Camera::stopRecord
    );
    connect(
        actions_->addAction(new QAction(QIcon(":/icons/take_picture.png"), QString(), this)),
        &QAction::triggered,
        &Camera::instance(),
        &Camera::capturePicture
    );

    addActions(actions_->actions());

    connect(cameraNamesComboBox_, &QComboBox::currentTextChanged, cameraResolutionComboBox_, &CameraFormatsComboBox::refresh);
}
