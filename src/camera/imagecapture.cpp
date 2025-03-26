#include "imagecapture.h"

#include "filesystem.h"

#include <QMediaCaptureSession>
#include <QVideoSink>


ImageCapture::ImageCapture(QMediaCaptureSession *mediaSession, QObject *parent)
    : QImageCapture(parent)
{
    mediaSession->setImageCapture(this);

    FileSystem::createDir(FileSystem::defaultPngDirName());

    connect(this, &QImageCapture::errorOccurred, [this](int id, [[maybe_unused]] QImageCapture::Error error, const QString &errorString) -> void {
        qWarning() << id << ", " << errorString;
    });
    connect(this, &QImageCapture::imageSaved, [this](int id, const QString &fileName) -> void {
        qWarning() << "id = " << id << ", " << fileName << "is saved";
    });
}

void ImageCapture::takePicture() noexcept
{
    if (isAvailable() && isReadyForCapture())
        captureToFile(FileSystem::defaultPngFileName());
}
