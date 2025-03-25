#include "maintoolbar.h"

#include "camera.h"
#include "cameranamescombobox.h"
#include "cameraformatscombobox.h"
#include "filesystem.h"

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
    actions_->addAction(addSeparator());
    connect(
        actions_->addAction(new QAction(QIcon(":/icons/picture_folder.png"), QString(), this)),
        &QAction::triggered,
        this,
        []() -> void {
            FileSystem::openDir(FileSystem::defaultPngDirName());
        }
    );
    connect(
        actions_->addAction(new QAction(QIcon(":/icons/video_folder.png"), QString(), this)),
        &QAction::triggered,
        this,
        []() -> void {
            FileSystem::openDir(FileSystem::defaultVideoDirName());
        }
    );

    addActions(actions_->actions());

    actions_->actions().at(0)->setToolTip("Record");
    actions_->actions().at(1)->setToolTip("Stop record");
    actions_->actions().at(2)->setToolTip("Take picture");
    actions_->actions().at(4)->setToolTip("Open picture folder");
    actions_->actions().at(5)->setToolTip("Open video folder");

    connect(cameraNamesComboBox_, &QComboBox::currentTextChanged, cameraResolutionComboBox_, &CameraFormatsComboBox::refresh);
}
