#pragma once

#include <QComboBox>


class QCameraFormat;

class CameraFormatsComboBox final : public QComboBox
{
    Q_OBJECT

public:
    explicit CameraFormatsComboBox(QWidget *parent = nullptr) noexcept;
    ~CameraFormatsComboBox() noexcept = default;

public slots:
    void refresh(const QString &cameraName) noexcept;

private:
    [[nodiscard]] QString formatToString(const QCameraFormat &format) const noexcept;

};
