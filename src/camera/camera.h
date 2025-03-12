#pragma once

#include <QCamera>
#include <QCameraDevice>
#include <QMap>
#include <QMediaDevices>
#include <QSize>


class ImageCapture;
class MediaRecorder;
class QAudioInput;
class QCameraDevice;
class QMediaCaptureSession;
class QVideoWidget;

using Resolutuion = QSize;

class CameraException : public std::runtime_error
{
public:
    CameraException(const QString &message) : std::runtime_error(message.toStdString()) {}
};

class Camera : public QCamera
{
    Q_OBJECT

public:
    Camera();
    ~Camera() noexcept = default;

    Camera(const Camera &) = delete;
    Camera(Camera &&) = delete;
    Camera &operator=(const Camera &) = delete;
    Camera &operator=(Camera &&) = delete;

    static Camera &instance();

    [[nodiscard]] QWidget *widget() noexcept;

public slots:
    void capturePicture();
    void setDevice(const QCameraDevice &device) noexcept;
    void setFormat(const QCameraFormat &format) noexcept;
    void startRecord();
    void stopRecord();

private:
    void checkCameraPermission();


    QMediaCaptureSession *mediaCaptureSession_;
    ImageCapture *imageCapture_;
    MediaRecorder *mediaRecorder_;
    QVideoWidget *widget_;

};
