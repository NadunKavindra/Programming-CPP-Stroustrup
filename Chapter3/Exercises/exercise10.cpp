/*
   Solution for Exercise 10 Chapter 3 on Page 86

   Takes an operation followed by two operands and outputs the result
*/

#include "../../std_lib_facilities.h"

int main()
{
   double operand1 = 0;
   double operand2 = 0;
   double result = 0;

   string operation;
   cout << "Enter an operation followed by two operands (seperated by spaces): ";
   cin >> operation;

   if (operation == "+") {
      cin >> operand1 >> operand2;
      result = operand1 + operand2;
   }
   else if (operation == "-") {
      cin >> operand1 >> operand2;
      result = operand1 - operand2;
   }
   else if (operation == "*") {
      cin >> operand1 >> operand2;
      result = operand1 * operand2;
   }
   else if (operation == "/") {
      cin >> operand1 >> operand2;
      result = operand1 / operand2;
   }
   else {
      simple_error("unknown operation");
   }
   cout << "Result of operation == " << result << '\n';
}
