#include "camera.h"

#include "imagecapture.h"
#include "mediarecorder.h"
#include "videowidget.h"

#include <QApplication>
#include <QCamera>
#include <QDir>
#include <QMediaCaptureSession>
#if QT_CONFIG(permissions)
#include <QPermission>
#endif
#include <QVideoWidget>


Camera::Camera()
    : QCamera()
    , mediaCaptureSession_(new QMediaCaptureSession(this))
    , imageCapture_(new ImageCapture(mediaCaptureSession_, this))
    , mediaRecorder_(new MediaRecorder(mediaCaptureSession_, this))
    , widget_(nullptr)
{
    try
    {
        checkCameraPermission();

        connect(this, &QCamera::errorOccurred, [this](QCamera::Error error, const QString &errorString) -> void {
            qWarning() << "ERROR :: " << errorString << ", code = " << error;
        });
    }
    catch (const CameraException &exception)
    {
        throw exception;
    }
}

Camera &Camera::instance()
{
    try
    {
        static auto camera = std::make_unique<Camera>();
        return *camera;
    }
    catch (const CameraException &exception)
    {
        qWarning() << exception.what();
    }
}

QWidget *Camera::widget() noexcept
{
    if (widget_ == nullptr)
        widget_ = new VideoWidget(mediaCaptureSession_);

    return widget_;
}

void Camera::capturePicture()
{
    imageCapture_->takePicture();
}

void Camera::setDevice(const QCameraDevice &device) noexcept
{
    setActive(false);
    setCameraDevice(device);
    setActive(true);

    device.isNull()
        ? mediaCaptureSession_->setCamera(nullptr)
        : mediaCaptureSession_->setCamera(this);
}

void Camera::setFormat(const QCameraFormat &format) noexcept
{
    mediaRecorder_->setVideoResolution(format.resolution());
    mediaRecorder_->setVideoFrameRate(format.maxFrameRate());
    setCameraFormat(format);
}

void Camera::startRecord()
{
    mediaRecorder_->startRecord();
}

void Camera::stopRecord()
{
    mediaRecorder_->stopRecord();
}

void Camera::checkCameraPermission()
{
#if QT_CONFIG(permissions)
    QCameraPermission cameraPermission;
    switch (qApp->checkPermission(cameraPermission))
    {
    case Qt::PermissionStatus::Undetermined:
        qApp->requestPermission(
            cameraPermission,
            this,
            [this]() -> void
            {
                try
                {
                    checkCameraPermission();
                }
                catch (const CameraException &exception)
                {
                    throw exception;
                }
            }
        );
        break;

    case Qt::PermissionStatus::Denied:
        throw CameraException("Camera permission is denied!");

    case Qt::PermissionStatus::Granted:
        break;
    }
#endif
}
