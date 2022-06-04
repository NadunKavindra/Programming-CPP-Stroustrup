/*
   Chapter 12 Exercise 12, Page 439

   Program that draw a "superellipse"
   More information and the equations used can be found here:
   https://en.wikipedia.org/wiki/Superellipse#:~:text=A%20superellipse%2C%20also%20known%20as,but%20a%20different%20overall%20shape.

   Requires FLTK to be installed.
   This is the only file written by me.
   All other files written by Bjarne Stroustrup.
*/

#include "Graph.h"
#include "Simple_window.h"
#include <cmath>
#include <exception>

/// Helper function to be used to calculate the x, y coordinates
/// @returns 1 if argument is positive, -1 if negative and 0 otherwise
int sign(const double d) { return (d > 0) - (d < 0); }


Point get_superellipse_point(const double a, const double b, const double n,
                            const double m, const double t)
{
   const double cos_t = cos(t);
   const double sin_t = sin(t);

   const double x = pow(abs(cos_t), 2 / m) * a * sign(cos_t);
   const double y = pow(abs(sin_t), 2 / n) * b * sign(sin_t);

   return Point(x, y);
}


int main()
try {
   constexpr double PI = 3.141592653589793238462643383279502884L;
   constexpr double TWO_PI = 2 * PI;

   constexpr int a = 400;
   constexpr int b = 300;
   constexpr double n = 2.5;
   constexpr double m = n;

   Simple_window window {Point{100, 100}, 1280, 720, "Superellipse"};

   Graph_lib::Closed_polyline superellipse;
   superellipse.set_color(Color::black);
   superellipse.set_style(Line_style{Line_style::solid, 3});

   // 1000 seems to give a reasoanble approximation
   constexpr int N = 1000;
   constexpr double increment = TWO_PI / N;

   for (double t = 0; t < TWO_PI; t += increment) {
      Point p = get_superellipse_point(a, b, n, m, t);

      // add spacing for output
      p.x += 640;
      p.y += 360;
      
      superellipse.add(p);
   }

   window.attach(superellipse);
   window.wait_for_button();
}
catch (const std::exception& e) {
   std::cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   std::cerr << "Oops: unknown exception\n";
   return 2;
}
