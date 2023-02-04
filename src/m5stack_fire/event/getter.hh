#pragma once

#include "M5Stack.h"
#include <tuple>
namespace m5stack_fire {
  namespace event {
    template <typename A>  
    struct coodinate_axis {
      A x_;
      A y_;
      A z_;

    public:
      coodinate_axis(A x, A y, A z) : x_(x), y_(y), z_(z) {}

      A x() const { return x_; }
      A y() const { return y_; }
      A z() const { return z_; }
    };

    template <typename A>
    struct imu_accel_getable {
      static coodinate_axis<A> operator()() {
      }
    };

    class getter {
      bool is_open();
      bool is_close();
    };
  }
}
