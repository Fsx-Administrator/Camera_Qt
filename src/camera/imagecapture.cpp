#include "imagecapture.h"

#include "filesystem.h"

#include <QDebug>
#include <QMediaCaptureSession>
#include <QVideoSink>


ImageCapture::ImageCapture(QMediaCaptureSession *mediaSession, QObject *parent)
    : QImageCapture(parent)
{
    mediaSession->setImageCapture(this);

    FileSystem fileSystem;
    fileSystem.createDir(fileSystem.pictureDirName());

    connect(this, &QImageCapture::errorOccurred, [this](int id, [[maybe_unused]] QImageCapture::Error error, const QString &errorString) -> void {
        qWarning() << id << ", " << errorString;
    });
}

void ImageCapture::takePicture() noexcept
{
    if (isAvailable() && isReadyForCapture())
        captureToFile(FileSystem{}.defaultPictureFileName());
}
