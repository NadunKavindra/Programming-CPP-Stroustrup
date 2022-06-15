#pragma once
#include "Graph.h"

namespace Graph_lib {

class Box : public Shape {
public:
   Box(Point top_left, int width, int height, int radius);

   void draw_lines() const;

private:
   int width;
   int height;
   int radius;
};

} // namespace Graph_lib
