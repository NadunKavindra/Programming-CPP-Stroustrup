#include "Arc.h"
#include <stdexcept>

namespace Graph_lib {

Arc::Arc(const Point center, const double radius, const double start_angle,
         const double stop_angle)
    : radius {radius}, start_angle {start_angle}, stop_angle {stop_angle}
{
   if (radius <= 0.0) {
      throw std::invalid_argument("Arc --> radius must have a positive value");
   }
   add(center);
   set_color(0);
}

void Arc::draw_lines() const
{
   fl_begin_line();
   fl_arc(point(0).x, point(0).y, radius, start_angle, stop_angle);
   fl_end_line();
}

} // namespace Graph_lib