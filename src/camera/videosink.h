#pragma once

#include <QVideoSink>


class VideoSink : public QVideoSink
{
    Q_OBJECT

public:
    explicit VideoSink(QObject *parent = nullptr) noexcept;
    ~VideoSink() noexcept = default;

};
