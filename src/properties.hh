#pragma once

namespace property {
  template <typename Type, typename Object, Type (Object::*getter)() const>
  class readonly {
    Object* object_;

  public:
    void operator()(Object* object) {
      object_ = object;
    }

    Type operator()() const {
      return (object_->*getter)();
    }
    operator Type() const {
      return (object_->*getter)();
    }
  };
}
