/*
   Chapter 16 Exercise 1&2, Page 578

   ButtonsWindow and MyWindow classes written by m-adaoglu.
   All other code written by Bjarne Stroustrup.

   Requires FLTK library to run.
*/
#include "ButtonsWindow.h"
#include "Gui.h"

#include <iostream>
#include <stdexcept>

using namespace Graph_lib;

int main()
try {
   ButtonsWindow window {Point {100, 100}, 1280, 720, "Exercises"};

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
