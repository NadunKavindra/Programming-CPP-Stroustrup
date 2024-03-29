/*
   Solution for Exercise 10 Chapter 3 on Page 86

   Takes an operation followed by two operands and outputs the result
*/

#include "../../std_lib_facilities.h"

int main()
{
   double operand1 = 0;
   double operand2 = 0;
   string operation;

   cout << "Enter an operation followed by two operands (seperated by spaces): ";
   if (!(cin >> operation >> operand1 >> operand2)) {
      simple_error("invalid input value");
   }

   double result = 0;

   if (operation == "+" || operation == "plus") {
      result = operand1 + operand2;
   }
   else if (operation == "-" || operation == "minus") {
      result = operand1 - operand2;
   }
   else if (operation == "*" || operation == "mul") {
      result = operand1 * operand2;
   }
   else if (operation == "/" || operation == "div") {
      result = operand1 / operand2;
   }
   else {
      simple_error("unknown operation");
   }

   cout << "Result of operation == " << result << '\n';
}
