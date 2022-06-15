/*
   Chapter 13 Exercises

   Due to time concerns, I only implemented the following exercises:

   Exercise 1: Define a class Arc that draws a part of an ellipse.
   Exercise 2: Define a class Box that is a rectangle with rounded corners.
   Exercise 8: Define a class RegularHexagon. Use the center and distance from
               center to corner points as constructor arguments.

   All other code written by Bjarne Stroustrup and requires FLTK library to run.
*/

#include "Arc.h"
#include "Box.h"
#include "Graph.h"
#include "RegularHexagon.h"
#include "Simple_window.h"

#include <exception>
#include <iostream>

using namespace Graph_lib;

int main()
try {
   Simple_window window {Point {100, 100}, 1280, 720, "Exercise"};

   Box box {Point {100, 100}, 1080, 500, 35};
   box.set_color(Color::dark_blue);
   box.set_style(Line_style {Line_style::solid, 3});

   Graph_lib::Arc arc {Point {640, 360}, 300, 90, 300};
   arc.set_color(Color::dark_green);
   arc.set_style(Line_style {Line_style::solid, 3});

   RegularHexagon hex {Point {640, 360}, 200};
   
   window.attach(arc);
   window.attach(box);
   window.attach(hex);
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
