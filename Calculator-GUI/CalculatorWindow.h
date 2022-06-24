#pragma once
#include "Calculator.h"
#include "Gui.h"
#include "Window.h"
#include <sstream>

namespace Graph_lib {

/// @author m-adaoglu
/// @brief A window displaying an input box (for mathematical statements), a submit
/// button and a output box for writing the result.
class CalculatorWindow : public Window {
public:
   CalculatorWindow(Point xy, int w, int h);

private:
   In_box input_box;
   Out_box output_box;

   Button submit_button;

   std::istringstream iss;
   std::ostringstream oss;

   Calculator calculator {iss, oss};

   void submit();

   static void cb_submit(Address, Address pw)
   {
      static_cast<CalculatorWindow*>(pw)->submit();
   }
};

} // namespace Graph_lib