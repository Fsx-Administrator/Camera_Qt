#include "mediarecorder.h"

#include "filesystem.h"

#include <QMediaCaptureSession>


MediaRecorder::MediaRecorder(QMediaCaptureSession *mediaSession, QObject *parent) noexcept
    : QMediaRecorder(parent)
{
    setEncodingMode(QMediaRecorder::TwoPassEncoding);
    mediaSession->setRecorder(this);

    FileSystem::createDir(FileSystem::defaultVideoDirName());

    connect(this, &QMediaRecorder::errorOccurred, [this]([[maybe_unused]] QMediaRecorder::Error error, const QString &errorString) -> void {
        qWarning() << errorString;
    });
    connect(this, &QMediaRecorder::recorderStateChanged, [this](QMediaRecorder::RecorderState state) -> void {
        qWarning() << state;
    });
}

inline bool MediaRecorder::isRecording() const noexcept
{
    return (recorderState() == QMediaRecorder::RecordingState);
}

void MediaRecorder::startRecord() noexcept
{
    if (!isRecording())
    {
        setOutputLocation(FileSystem::defaultVideoUrl());
        record();
    }
}

void MediaRecorder::stopRecord() noexcept
{
    if (isRecording())
        stop();
}
