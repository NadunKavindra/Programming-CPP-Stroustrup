#pragma once
#include "MyWindow.h"

namespace Graph_lib {

/// @brief A window with 4-by-4 checkerboard of square buttons
/// On press, the button becomes red (until another button is pressed)
class ButtonsWindow : public MyWindow {
public:
   ButtonsWindow(Point xy, int w, int h, const string& title);

private:
   const string button_label = "Click Me!";
   Button top_left;
   Button top_right;
   Button bottom_left;
   Button bottom_right;

   // Buttons can't have color so "fake" it
   Rectangle red_button;

   void button_pressed(const Button& b, const Color color = Color::red);

   // A more general solution is possible, using a single callback function
   // However, FLTK does not behave well with raw addresses
   // So using a single function for every button
   static void cb_top_left(Address, Address pw);
   static void cb_top_right(Address, Address pw);
   static void cb_bottom_left(Address, Address pw);
   static void cb_bottom_right(Address, Address pw);
};
} // namespace Graph_lib
