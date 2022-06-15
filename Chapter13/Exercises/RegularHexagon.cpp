#define _USE_MATH_DEFINES
#include "RegularHexagon.h"
#include "Point.h"

#include <cmath>
#include <stdexcept>

namespace Graph_lib {

RegularHexagon::RegularHexagon(const Point center, const int circumradius)
    : center {center}, circumradius {circumradius}
{
   if (circumradius < 1) {
      throw std::invalid_argument(
          "RegularHexagon --> circumradius must be positive");
   }
   set_color(0);
   add_points();
}

void RegularHexagon::add_points()
{
   for (int angle = 0; angle < 360; angle += 60) {
      // Using trigonometry (e.g. SOH CAH TOA) to calculate the corners
      add(Point(circumradius * cos(angle * M_PI / 180) + center.x,
                circumradius * sin(angle * M_PI / 180) + center.y));
   }
}

} // namespace Graph_lib
