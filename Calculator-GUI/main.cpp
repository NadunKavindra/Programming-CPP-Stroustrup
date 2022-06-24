/*
   Chapter 16 Exercise 9, Page 579

   Modified the calculator from Chapter 7 to get it's input from a GUI input box
   and write to a output box.

   Minimal time was spent on the aesthetics, usability and scalability of the GUI.
*/

#include "CalculatorWindow.h"
#include "Gui.h"
#include <exception>
#include <iostream>

int main()
try {
   Graph_lib::CalculatorWindow calculator {Graph_lib::Point {100, 100}, 1280, 720};
   return Graph_lib::gui_main();
}
catch (const std::exception& e) {
   std::cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   std::cerr << "Error: unknown exception\n";
   return 2;
}
