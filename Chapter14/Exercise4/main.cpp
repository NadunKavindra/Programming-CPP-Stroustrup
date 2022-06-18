/*
   Chapter 14 Exercise 4, Pages 516
      Define a class ImmobileCircle which is just like Circle but can't
      be moved.

   All other code written by Bjarne Stroustrup and requires FLTK library to run.
*/

#include "Graph.h"
#include "Simple_window.h"
#include "ImmobileCircle.h"

#include <exception>
#include <iostream>

int main()
try {
   Simple_window window {Point {100, 100}, 1280, 720, "Exercises"};

   ImmobileCircle immobile_circle {Point {640, 360}, 200};
   immobile_circle.set_fill_color(0);

   window.attach(immobile_circle);
   window.wait_for_button();

   return 0;
}
catch (const std::exception& e) {
   std::cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   std::cerr << "Oops: unknown exception\n";
   return 2;
}
