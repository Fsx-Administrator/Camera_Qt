#include "filesystem.h"

#include <QDateTime>
#include <QDesktopServices>
#include <QDir>
#include <QFileDialog>


QString FileSystem::pictureDirName_ = QDir::currentPath() + "/img";
QString FileSystem::videoDirName_ = QDir::currentPath() + "/video";

FileSystem::FileSystem() {}

void FileSystem::choosePictureDirName()
{
    const auto dirName = QFileDialog::getExistingDirectory(
        nullptr,
        QObject::tr("Choose picture folder"),
        pictureDirName_
    );

    if (dirName.isEmpty())
        return;

    pictureDirName_ = dirName;
}

void FileSystem::chooseVideoDirName()
{
    const auto dirName = QFileDialog::getExistingDirectory(
        nullptr,
        QObject::tr("Choose video folder"),
        videoDirName_
    );

    if (dirName.isEmpty())
        return;

    videoDirName_ = dirName;
}

void FileSystem::createDir(const QString &name) const
{
    if (!QDir{}.exists(name))
        QDir{}.mkdir(name);
}

QString FileSystem::defaultPictureFileName() const
{
    return _PNG_FILE_NAME_PATTERN_.arg(pictureDirName_, QDateTime::currentDateTime().toString("yyyy.MM.dd hh.mm.ss.zzz"));
}

QUrl FileSystem::defaultVideoUrl() const
{
    return QUrl{_VIDEO_FILE_NAME_PATTERN_.arg(videoDirName_, QDateTime::currentDateTime().toString("yyyy.MM.dd hh.mm.ss.zzz"))};
}

void FileSystem::openDir(const QString &name) const
{
    QDesktopServices::openUrl(QUrl{QDir{name}.absolutePath()});
}

const QString &FileSystem::pictureDirName() const
{
    return pictureDirName_;
}

QString FileSystem::pwd() const
{
    return QDir::currentPath();
}

const QString &FileSystem::videoDirName() const
{
    return videoDirName_;
}
