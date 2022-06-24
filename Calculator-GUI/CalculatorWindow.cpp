#include "CalculatorWindow.h"

namespace Graph_lib {
CalculatorWindow::CalculatorWindow(Point xy, int w, int h)
    : Window {xy, w, h, "Calculator"},
      input_box {Point {100, h / 2}, w / 5, h / 5, "Input"},
      output_box {Point {500 + w / 5, h / 2}, w / 5, h / 5, "Result"},
      submit_button {Point {200 + w / 5, h / 2}, w / 6, h / 5, "Calculate",
                     cb_submit}
{
   attach(input_box);
   attach(output_box);
   attach(submit_button);
}

void CalculatorWindow::submit()
{
   iss.str(input_box.get_string());
   calculator.calculate();
   output_box.put(oss.str());

   iss.clear();
   oss.str("");
}

} // namespace Graph_lib