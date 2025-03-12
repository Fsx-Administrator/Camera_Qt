#pragma once

#include <QVideoWidget>


class QMediaCaptureSession;

class VideoWidget : public QVideoWidget
{
    Q_OBJECT

public:
    explicit VideoWidget(QMediaCaptureSession *mediaSession, QWidget *parent = nullptr) noexcept;
    ~VideoWidget() noexcept = default;

};
