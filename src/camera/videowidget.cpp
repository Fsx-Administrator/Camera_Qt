#include "videowidget.h"

#include <QCamera>
#include <QMediaCaptureSession>


VideoWidget::VideoWidget(QMediaCaptureSession *mediaSession, QWidget *parent) noexcept
    : QVideoWidget(parent)
{
    setAspectRatioMode(Qt::KeepAspectRatio);
    setMinimumSize(mediaSession->camera()->cameraFormat().resolution() * 0.5);
    mediaSession->setVideoOutput(this);
}
