#include "maintoolbar.h"

#include "camera.h"
#include "cameranamescombobox.h"
#include "cameraformatscombobox.h"
#include "filesystem.h"

#include <QActionGroup>


MainToolBar::MainToolBar(QWidget *parent) noexcept
    : QToolBar{parent}
    , cameraNamesComboBox_{new CameraNamesComboBox{this}}
    , cameraResolutionComboBox_{new CameraFormatsComboBox{this}}
    , actions_{new QActionGroup{this}}
{
    addWidget(cameraNamesComboBox_);
    addWidget(cameraResolutionComboBox_);

    setIconSize(QSize{32, 32});

    connect(
        actions_->addAction(new QAction{QIcon{":/icons/record.png"}, tr("Start record"), this}),
        &QAction::triggered,
        &Camera::instance(),
        &Camera::startRecord
    );
    connect(
        actions_->addAction(new QAction{QIcon{":/icons/stop_record.png"}, tr("Stop record"), this}),
        &QAction::triggered,
        &Camera::instance(),
        &Camera::stopRecord
    );
    connect(
        actions_->addAction(new QAction{QIcon{":/icons/take_picture.png"}, tr("Take picture"), this}),
        &QAction::triggered,
        &Camera::instance(),
        &Camera::capturePicture
    );
    actions_->addAction(addSeparator());
    connect(
        actions_->addAction(new QAction{QIcon{":/icons/picture_folder.png"}, tr("Open picture folder"), this}),
        &QAction::triggered,
        this,
        [this]() -> void {
            FileSystem fileSystem;
            fileSystem.openDir(fileSystem.pictureDirName());
        }
    );
    connect(
        actions_->addAction(new QAction{QIcon{":/icons/video_folder.png"}, tr("Open video folder"), this}),
        &QAction::triggered,
        this,
        []() -> void {
            FileSystem fileSystem;
            fileSystem.openDir(fileSystem.videoDirName());
        }
    );
    actions_->addAction(addSeparator());
    connect(
        actions_->addAction(new QAction{QIcon{":/icons/choose_picture_folder.png"}, tr("Choose picture folder"), this}),
        &QAction::triggered,
        this,
        []() -> void {
            FileSystem{}.choosePictureDirName();
        }
    );
    connect(
        actions_->addAction(new QAction{QIcon{":/icons/choose_video_folder.png"}, tr("Choose video folder"), this}),
        &QAction::triggered,
        this,
        []() -> void {
            FileSystem{}.chooseVideoDirName();
        }
    );

    addActions(actions_->actions());

    actions_->actions().at(0)->setToolTip(tr("Start record"));
    actions_->actions().at(1)->setToolTip(tr("Stop record"));
    actions_->actions().at(2)->setToolTip(tr("Take picture"));
    actions_->actions().at(4)->setToolTip(tr("Open picture folder"));
    actions_->actions().at(5)->setToolTip(tr("Open video folder"));
    actions_->actions().at(6)->setToolTip(tr("Choose picture folder"));
    actions_->actions().at(7)->setToolTip(tr("Choose video folder"));

    connect(cameraNamesComboBox_, &QComboBox::currentTextChanged, cameraResolutionComboBox_, &CameraFormatsComboBox::refresh);
}
