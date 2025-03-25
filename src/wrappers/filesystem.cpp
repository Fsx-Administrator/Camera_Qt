#include "filesystem.h"

#include <QDateTime>
#include <QDesktopServices>
#include <QDir>


void FileSystem::createDir(const QString &name)
{
    if (!QDir().exists(name))
        QDir().mkdir(name);
}

QString FileSystem::defaultPngDirName()
{
    return _PICTURES_DIR_NAME_;
}

QString FileSystem::defaultPngFileName()
{
    return _PNG_FILE_NAME_PATTERN_.arg(pwd(), _PICTURES_DIR_NAME_, QDateTime::currentDateTime().toString("yyyy.MM.dd hh.mm.ss.zzz"));
}

QString FileSystem::defaultVideoDirName()
{
    return _VIDEO_DIR_NAME_;
}

QUrl FileSystem::defaultVideoUrl()
{
    return QUrl(_VIDEO_FILE_NAME_PATTERN_.arg(pwd(), _VIDEO_DIR_NAME_, QDateTime::currentDateTime().toString("yyyy.MM.dd hh.mm.ss.zzz")));
}

void FileSystem::openDir(const QString &name)
{
    QDesktopServices::openUrl(QUrl(QDir(name).absolutePath()));
}

QString FileSystem::pwd()
{
    return QDir::currentPath();
}
