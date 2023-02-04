#pragma once

#include <memory>

template <typename DeviceType>
class laptop_cover {
  const std::unique_ptr<m5stack::device<DeviceType>> attached_device;
};
