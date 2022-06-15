#pragma once
#include "Graph.h"
namespace Graph_lib {

class RegularPolygon : public Polygon {
public:
   RegularPolygon(Point center, int circumradius, int n);

private:
   Point center;
   int circumradius;
   int n;   // The number of sides

   void add_points();
};

} // namespace Graph_lib
