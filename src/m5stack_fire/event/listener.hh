#pragma once

namespace m5stack_fire {
  namespace event {
    class listener {
      template <typename F>
      void on_open(F handler);

      template <typename F>
      void on_close(F handler);
    };
  }
}
