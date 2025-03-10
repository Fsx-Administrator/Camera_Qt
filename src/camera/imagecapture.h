#pragma once

#include <QImageCapture>


class QMediaCaptureSession;

class ImageCapture final : public QImageCapture
{
    Q_OBJECT

public:
    explicit ImageCapture(QMediaCaptureSession *mediaSession, QObject *parent = nullptr);
    ~ImageCapture() noexcept = default;

public slots:
    void takePicture() noexcept;

};
