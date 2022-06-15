#include "Box.h"
#include "Graph.h"
#include <stdexcept>

namespace Graph_lib {

Box::Box(const Point top_left, const int width, const int height, const int radius)
    : width {width}, height {height}, radius {radius}
{
   if (radius < 1 || width < 1 || height < 1) {
      throw std::invalid_argument(
          "Box --> radius, width and height must all be positive");
   }

   if (radius * 2 > height) {
      throw std::invalid_argument(
          "Box --> radius must be less than or equal half the height");
   }

   add(top_left);
   set_color(0);
}

void Box::draw_lines() const
{
   const Point origin = point(0);
   const int diameter = radius * 2;

   if (color().visibility()) {
      fl_line(origin.x + radius, origin.y, origin.x + width - radius, origin.y);
      fl_line(origin.x, origin.y + radius, origin.x, origin.y + height - radius);

      fl_line(origin.x + radius, origin.y + height, origin.x + width - radius,
              origin.y + height);
      fl_line(origin.x + width, origin.y + radius, origin.x + width,
              origin.y + height - radius);

      fl_arc(origin.x + width - diameter, origin.y, diameter, diameter, 0, 90);
      fl_arc(origin.x, origin.y, diameter, diameter, 90, 180);
      fl_arc(origin.x, origin.y + height - diameter, diameter, diameter, 180, 270);
      fl_arc(origin.x + width - diameter, origin.y + height - diameter, diameter,
             diameter, 270, 360);
   }
}

} // namespace Graph_lib
