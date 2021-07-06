/*
   Exercise 5 on Page 128

   A very simple calculator
*/

#include "../../std_lib_facilities.h"

int main()
{
   double val1 = 0;
   double val2 = 0;
   char operation = 0;

   cout << "Enter two floating-point values followed by an operator (all seperated by a space): ";
   cin >> val1 >> val2 >> operation;

   switch (operation) {
   case '+':
      cout << "The sum of " << val1 << " and " << val2 << " is " << val1 + val2 << '\n';
      break;
   case '-':
      cout << "The difference between " << val1 << " and " << val2 << " is " << val1 - val2 << '\n';
      break;
   case '*':
      cout << "The product of " << val1 << " and " << val2 << " is " << val1 * val2 << '\n';
      break;
   case '/':
      cout << val1 << " divided by " << val2 << " is " << val1 / val2 << '\n';
      break;
   default:
      simple_error("unknown operator");
   }
}