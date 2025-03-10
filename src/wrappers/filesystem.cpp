#include "filesystem.h"

#include <QDateTime>
#include <QDir>

void FileSystem::createDirection(const QString &name)
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

QString FileSystem::pwd()
{
    return QDir::currentPath();
}
