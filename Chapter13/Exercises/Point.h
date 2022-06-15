
#ifndef POINT_GUARD
#define POINT_GUARD

#include <ostream>

typedef void (*Callback)(void*, void*);

namespace Graph_lib {

struct Point {
   int x, y;
   Point(int xx, int yy) : x(xx), y(yy) {}
   Point() : x(0), y(0) {}

   Point& operator+=(Point d)
   {
      x += d.x;
      y += d.y;
      return *this;
   }
};

inline bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }

inline bool operator!=(Point a, Point b) { return !(a == b); }

// Authored by m-adaoglu
inline std::ostream& operator<<(std::ostream& os, const Point& p)
{
   return os << '(' << p.x << ',' << p.y << ')';
}

} // namespace Graph_lib
#endif