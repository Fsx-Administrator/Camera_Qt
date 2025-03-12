#include "cameraformatscombobox.h"

#include "camera.h"
#include "videoinputs.h"


CameraFormatsComboBox::CameraFormatsComboBox(QWidget *parent) noexcept
    : QComboBox(parent)
{
    connect(this, &QComboBox::currentIndexChanged, this, [this](int index) -> void {
        if (index < 0)
            index = 0;

        Camera::instance().setFormat(itemData(index).value<QCameraFormat>());
    });

    const auto devices = VideoInputs::instance().devices();
    if (!devices.empty())
        refresh(devices.firstKey());
}

void CameraFormatsComboBox::refresh(const QString &cameraName) noexcept
{
    clear();

    auto formats = VideoInputs::instance().formats()[cameraName];
    std::ranges::sort(formats, [](const QCameraFormat a, const QCameraFormat b) -> bool {
        if (a.pixelFormat() == b.pixelFormat())
        {
            if (a.resolution().width() == b.resolution().width())
                return a.maxFrameRate() > b.maxFrameRate();
            else
                return a.resolution().width() > b.resolution().width();
        }
        else
        {
            return a.pixelFormat() > b.pixelFormat();
        }
    });
    for (const auto &format : formats)
        addItem(formatToString(format), QVariant::fromValue(format));
}

QString CameraFormatsComboBox::formatToString(const QCameraFormat &format) const noexcept
{
    return QVideoFrameFormat::pixelFormatToString(format.pixelFormat())
           + ", " + QString::number(format.resolution().width())
           + "x" + QString::number(format.resolution().height())
           + ", " + QString::number(format.minFrameRate())
           + "-" + QString::number(format.maxFrameRate())
           + " FPS";
}
