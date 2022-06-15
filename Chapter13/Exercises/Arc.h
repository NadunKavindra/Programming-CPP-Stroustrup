#pragma once
#include "Graph.h"

namespace Graph_lib {

class Arc : public Shape {
public:
   Arc(Point center, double radius, double start_angle, double stop_angle);

   void draw_lines() const;

private:
   double radius;
   double start_angle;
   double stop_angle;
};

} // namespace Graph_lib
