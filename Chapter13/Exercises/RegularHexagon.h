#pragma once
#include "Graph.h"

namespace Graph_lib {

class RegularHexagon : public Polygon {
public:
   RegularHexagon(Point center, int circumradius);

private:
   Point center;
   int circumradius;
   void add_points();
};

} // namespace Graph_lib
