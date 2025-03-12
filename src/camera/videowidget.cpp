#include "videowidget.h"

#include <QMediaCaptureSession>


VideoWidget::VideoWidget(QMediaCaptureSession *mediaSession, QWidget *parent) noexcept
    : QVideoWidget(parent)
{
    setAspectRatioMode(Qt::KeepAspectRatio);
    mediaSession->setVideoOutput(this);
}
