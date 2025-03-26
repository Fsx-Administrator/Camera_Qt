#include "videosink.h"

#include <QDebug>
#include <QVideoFrame>


VideoSink::VideoSink(QObject *parent) noexcept
    : QVideoSink{parent}
{
    connect(this, &QVideoSink::videoFrameChanged, [this](const QVideoFrame &frame) -> void {
        qDebug() << "changed";
        auto temp = frame;
        temp.setMirrored(true);
        setVideoFrame(temp);
    });
}
