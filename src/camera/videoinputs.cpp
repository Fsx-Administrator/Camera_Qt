#include "videoinputs.h"

#include <QDebug>


VideoDevicesMap VideoInputs::devices() noexcept
{
    VideoDevicesMap result;

    const auto inputs = QMediaDevices::videoInputs();
    for (const auto &input : inputs)
        result[input.description()] = input;

    return result;
}

VideoFormatsMap VideoInputs::formats() noexcept
{
    VideoFormatsMap result;

    const auto inputs = QMediaDevices::videoInputs();
    for (const auto &input : inputs)
        result[input.description()] = input.videoFormats();

    return result;
}

VideoInputs &VideoInputs::instance()
{
    static VideoInputs instance_;
    return instance_;
}

QMediaDevices &VideoInputs::mediaDevices() noexcept
{
    return mediaDevices_;
}
