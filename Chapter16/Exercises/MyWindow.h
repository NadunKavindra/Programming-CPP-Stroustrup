#pragma once
#include "Gui.h"
#include "Simple_window.h"

namespace Graph_lib {

/// @brief Just like a Simple_window except it also has a button "Quit"
class MyWindow : public Simple_window {
public:
   MyWindow(Point xy, int w, int h, const std::string& title);

private:
   Button quit_button;

   static void cb_quit(Address, Address pw) { static_cast<MyWindow*>(pw)->hide(); }
};
} // namespace Graph_lib