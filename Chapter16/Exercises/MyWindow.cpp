#include "MyWindow.h"

namespace Graph_lib {
MyWindow::MyWindow(const Point xy, const int w, const int h,
                   const std::string& title)
    : Simple_window {xy, w, h, title},
      quit_button {Point {w - 145, 0}, 70, 20, "Quit", cb_quit}
{
   attach(quit_button);
}

}; // namespace Graph_lib