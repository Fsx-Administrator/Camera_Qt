#include "videowidget.h"

#include <QCamera>
#include <QMediaCaptureSession>
#include <QVideoSink>


VideoWidget::VideoWidget(QMediaCaptureSession *mediaSession, QWidget *parent) noexcept
    : QVideoWidget(parent)
{
    setAspectRatioMode(Qt::KeepAspectRatio);
    if (mediaSession->camera())
        setMinimumSize(mediaSession->camera()->cameraFormat().resolution() * 0.5);
    mediaSession->setVideoOutput(this);
}
