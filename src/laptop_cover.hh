#pragma once

#include <functional>
#include <vector>
#include <memory>
#include <type_traits>

#include "m5stack/fire/device.hh"

using device = m5stack::fire::device;

struct event_types {
  enum struct openable {
    open,
    close,
    size
  };
};

template <typename Event_type>
class events {};

template<>
class events<event_types::openable> {
  using Handler = std::function<void()>;

  std::vector<Handler> handlers;

public:
  void on(event_types::openable kind, Handler handler);

  void join();
};

class laptop_cover {
  using event_type = event_types::openable;
  std::unique_ptr<device> attached_device_;
  std::unique_ptr<events<event_type>> events_;

public:
  const device& attached_device() const {
    return *attached_device_;
  }

  const events<event_type>& event() const {
    return *events_;
  }

  explicit laptop_cover(device* attached_device, events<event_type>* event)
    : attached_device_(attached_device), events_(event) {}
};
