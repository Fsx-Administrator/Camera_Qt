#pragma once

#include <QString>
#include <QUrl>


class FileSystem
{

public:
    FileSystem();
    ~FileSystem() = default;

    FileSystem(const FileSystem &) = delete;
    FileSystem(FileSystem &&) = delete;
    FileSystem &operator=(const FileSystem &) = delete;
    FileSystem &operator=(FileSystem &&) = delete;

    void choosePictureDirName();
    void chooseVideoDirName();
    void createDir(const QString &name) const;
    [[nodiscard]] QString defaultPictureFileName() const;
    [[nodiscard]] QUrl defaultVideoUrl() const;
    void openDir(const QString &name) const;
    [[nodiscard]] const QString &pictureDirName() const;
    [[nodiscard]] QString pwd() const;
    [[nodiscard]] const QString &videoDirName() const;

private:
    static inline const QString _PNG_FILE_NAME_PATTERN_ = "%1/%2.png";
    static inline const QString _VIDEO_FILE_NAME_PATTERN_ = "%1/%2.mp4";
    static QString pictureDirName_;
    static QString videoDirName_;

};
