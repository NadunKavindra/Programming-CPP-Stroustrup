#include "ButtonsWindow.h"

namespace Graph_lib {

ButtonsWindow::ButtonsWindow(Point xy, int w, int h, const string& title)
   : MyWindow {xy, w, h, title},
     top_left {Point {0, 0}, w / 2 - 75, h / 2, button_label, cb_top_left},
     top_right {Point {w / 2 - 75, 0}, w / 2 - 75, h / 2, button_label,
                cb_top_right},
     bottom_left {Point {0, h / 2}, w / 2 - 75, h / 2, button_label, cb_bottom_left},
     bottom_right {Point {w / 2 - 75, h / 2}, w / 2 - 75, h / 2, button_label,
                   cb_bottom_right},
     // Place it out of sight
     red_button {Point {w + 1000, h + 1000}, w / 2 - 75, h / 2}
{
   attach(top_left);
   attach(top_right);
   attach(bottom_left);
   attach(bottom_right);
   red_button.set_color(Color::invisible);
   red_button.set_fill_color(Color::red);
   attach(red_button);
}

void ButtonsWindow::button_pressed(const Button& b, const Color color)
{
   red_button.move(b.loc.x - red_button.point(0).x, b.loc.y - red_button.point(0).y);
   redraw();
}

void ButtonsWindow::cb_top_left(Address, Address pw)
{
   ButtonsWindow* window = static_cast<ButtonsWindow*>(pw);
   window->button_pressed(window->top_left);
}

void ButtonsWindow::cb_top_right(Address, Address pw)
{
   ButtonsWindow* window = static_cast<ButtonsWindow*>(pw);
   window->button_pressed(window->top_right);
}

void ButtonsWindow::cb_bottom_left(Address, Address pw)
{
   ButtonsWindow* window = static_cast<ButtonsWindow*>(pw);
   window->button_pressed(window->bottom_left);
}

void ButtonsWindow::cb_bottom_right(Address, Address pw)
{
   ButtonsWindow* window = static_cast<ButtonsWindow*>(pw);
   window->button_pressed(window->bottom_right);
}

} // namespace Graph_lib