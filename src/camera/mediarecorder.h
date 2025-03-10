#pragma once

#include <QMediaRecorder>
#include <qglobal.h>

class MediaRecorder : public QMediaRecorder
{
    Q_OBJECT

public:
    explicit MediaRecorder(QMediaCaptureSession *mediaSession, QObject *parent = nullptr) noexcept;
    ~MediaRecorder() noexcept = default;

    [[nodiscard]] inline bool isRecording() const noexcept;

public slots:
    void startRecord() noexcept;
    void stopRecord() noexcept;

};
