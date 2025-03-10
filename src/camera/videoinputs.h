#pragma once

#include <QCameraDevice>
#include <QCameraFormat>
#include <QMap>
#include <QMediaDevices>


using VideoFormatsMap = QMap<QString, QList<QCameraFormat>>;
using VideoDevicesMap = QMap<QString, QCameraDevice>;

class VideoInputs
{

public:
    VideoInputs(const VideoInputs &) = delete;
    VideoInputs(VideoInputs &&) = delete;
    VideoInputs &operator=(const VideoInputs &) = delete;
    VideoInputs &operator=(VideoInputs &&) = delete;

    [[nodiscard]] VideoDevicesMap devices() noexcept;
    [[nodiscard]] VideoFormatsMap formats() noexcept;
    static VideoInputs &instance();
    [[nodiscard]] QMediaDevices &mediaDevices() noexcept;

private:
    VideoInputs() noexcept = default;
    ~VideoInputs() noexcept = default;

    QMediaDevices mediaDevices_;

};
