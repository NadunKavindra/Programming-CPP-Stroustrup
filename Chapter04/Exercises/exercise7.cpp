/*
   Exercise 7 on Page 128

   The calculator from exercise 5
   Modified to accept (only) single digit numbers as either digits
   or spelled out
*/

#include "../../std_lib_facilities.h"

/// Returns the value of a spelled out digit or a digit entered as a string
int string_to_int(const string input)
{
   if (input.size() == 0) {
      simple_error("cannot convert empty string");
   }

   const vector<string> numbers {"zero", "one", "two",   "three", "four",
                                 "five", "six", "seven", "eight", "nine"};

   // check if input is a digit such as '1', '2' etc.
   if (input.size() == 1) {
      const int digit = input[0] - 48; // ASCII digits start at 48

      if (digit >= 0 && digit <= 9) {
         return digit;
      }
   }

   // check if input is a spelled out digit such as "one", "two" etc.
   for (size_t i = 0; i < numbers.size(); ++i) {
      if (input == numbers[i]) {
         return i;
      }
   }
   simple_error("unknown digit");
}

int main()
{
   string input1;
   string input2;
   char operation = 0;

   cout << "Enter two digits followed by an operator (all seperated by a space): ";

   if (!(cin >> input1 >> input2 >> operation)) {
      simple_error("invalid input value");
   }

   const int digit1 = string_to_int(input1);
   const int digit2 = string_to_int(input2);

   switch (operation) {
   case '+':
      cout << "The sum of " << digit1 << " and " << digit2 << " is "
           << digit1 + digit2 << '\n';
      break;
   case '-':
      cout << "The difference between " << digit1 << " and " << digit2 << " is "
           << digit1 - digit2 << '\n';
      break;
   case '*':
      cout << "The product of " << digit1 << " and " << digit2 << " is "
           << digit1 * digit2 << '\n';
      break;
   case '/':
      cout << digit1 << " divided by " << digit2 << " is " << digit1 / digit2
           << '\n';
      break;
   default:
      simple_error("unknown operator");
   }
}
