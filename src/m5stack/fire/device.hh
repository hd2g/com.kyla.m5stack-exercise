#pragma once

#include <memory>

#include "../../properties.hh"

namespace m5stack {
  namespace fire {
    class display_printer {};

    class device {
      std::unique_ptr<display_printer> display_;
      const display_printer& get_display() const { return *display_; }

    public:
      property::readonly<const display_printer&, device, &device::get_display> display;

      explicit device() : display_(new display_printer) {
        display(this);
      }
    };
  }
}
