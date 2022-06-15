#define _USE_MATH_DEFINES
#include "RegularPolygon.h"
#include "Point.h"
#include <cmath>
#include <stdexcept>

namespace Graph_lib {

RegularPolygon::RegularPolygon(const Point center, const int circumradius,
                               const int n)
    : center {center}, circumradius {circumradius}, n {n}
{
   if (circumradius < 1) {
      throw std::invalid_argument(
          "RegularPolygon --> circumradius must be positive");
   }

   if (n < 3) {
      throw std::invalid_argument(
          "RegularPolygon --> number of sides (n) must be greater than 2");
   }
   set_color(0);
   add_points();
}

void RegularPolygon::add_points()
{
   const int increment = 360 / n;
   for (int angle = 0; angle < 360; angle += increment) {
      // Using trigonometry (e.g. SOH CAH TOA) to calculate the corners
      add(Point(circumradius * cos(angle * M_PI / 180) + center.x,
                circumradius * sin(angle * M_PI / 180) + center.y));
   }
}

} // namespace Graph_lib