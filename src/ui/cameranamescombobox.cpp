#include "cameranamescombobox.h"

#include "camera.h"
#include "videoinputs.h"


CameraNamesComboBox::CameraNamesComboBox(QWidget *parent) noexcept
    : QComboBox(parent)
{
    connect(&VideoInputs::instance().mediaDevices(), &QMediaDevices::videoInputsChanged, this, &CameraNamesComboBox::refresh);
    connect(this, &QComboBox::currentIndexChanged, this, [this](int index) -> void {
        if (index < 0)
            Camera::instance().setDevice(QCameraDevice());
        else
            Camera::instance().setDevice(itemData(index).value<QCameraDevice>());
    });

    refresh();
}

void CameraNamesComboBox::refresh() noexcept
{
    clear();

    const auto devices = VideoInputs::instance().devices();
    const auto deviceNames = devices.keys();
    for (const auto &deviceName : deviceNames)
        addItem(deviceName, QVariant::fromValue(devices[deviceName]));
}
