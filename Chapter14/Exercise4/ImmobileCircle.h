#pragma once
#include "Graph.h"

namespace Graph_lib {

/// @brief Just like a Circle but cannot be moved.
class ImmobileCircle : public Circle {
   using Circle::Circle;

private:
   /// Note that there is no way to delete a virtual function.
   /// Move can still be called by a base class, but will do nothing.
   void move(int dx, int dy) override { }
};

} // namespace Graph_lib