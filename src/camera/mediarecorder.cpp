#include "mediarecorder.h"

#include "filesystem.h"

#include <QMediaCaptureSession>


MediaRecorder::MediaRecorder(QMediaCaptureSession *mediaSession, QObject *parent) noexcept
    : QMediaRecorder(parent)
{
    setEncodingMode(QMediaRecorder::TwoPassEncoding);
    mediaSession->setRecorder(this);

    FileSystem fileSystem;
    fileSystem.createDir(fileSystem.videoDirName());

    connect(this, &QMediaRecorder::errorOccurred, [this]([[maybe_unused]] QMediaRecorder::Error error, const QString &errorString) -> void {
        qWarning() << errorString;
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
        setOutputLocation(FileSystem{}.defaultVideoUrl());
        record();
    }
}

void MediaRecorder::stopRecord() noexcept
{
    if (isRecording())
        stop();
}
