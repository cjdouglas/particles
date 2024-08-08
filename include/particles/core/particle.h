#pragma once

#include "particles/math/vec.h"

namespace particles {
class particle {
 public:
  void tick(float delta);

 private:
  vec position_;
  vec velocity_;
  vec acceleration_;
};
}  // namespace particles
