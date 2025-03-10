#pragma once

#include <QString>
#include <QUrl>


class FileSystem
{

public:
    FileSystem() = delete;
    ~FileSystem() = delete;

    FileSystem(const FileSystem &) = delete;
    FileSystem(FileSystem &&) = delete;
    FileSystem &operator=(const FileSystem &) = delete;
    FileSystem &operator=(FileSystem &&) = delete;

    static void createDirection(const QString &name);
    [[nodiscard]] static QString defaultPngDirName();
    [[nodiscard]] static QString defaultPngFileName();
    [[nodiscard]] static QString defaultVideoDirName();
    [[nodiscard]] static QUrl defaultVideoUrl();
    [[nodiscard]] static QString pwd();

private:
    static inline const QString _PICTURES_DIR_NAME_ = "img";
    static inline const QString _VIDEO_DIR_NAME_ = "video";
    static inline const QString _PNG_FILE_NAME_PATTERN_ = "%1/%2/%3.png";
    static inline const QString _VIDEO_FILE_NAME_PATTERN_ = "%1/%2/%3.mp4";

};
