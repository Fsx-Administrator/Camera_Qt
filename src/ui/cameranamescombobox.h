#pragma once

#include <QComboBox>


class CameraNamesComboBox final : public QComboBox
{
    Q_OBJECT

public:
    explicit CameraNamesComboBox(QWidget *parent = nullptr) noexcept;
    ~CameraNamesComboBox() noexcept = default;

private slots:
    void refresh() noexcept;

};
