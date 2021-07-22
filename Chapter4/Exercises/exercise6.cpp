/*
   Exercise 6 on Page 128-129

   Converts a digit to its corresponding spelled-out value and vice versa
*/

#include "../../std_lib_facilities.h"

int main()
{
   const vector<string> numbers = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

   string user_input = "";

   cout << "Please enter the digit to be converted (enter '|' to exit): ";

   while (cin >> user_input && user_input != "|") {
      bool found = false;

      if (user_input.size() == 1) {
         const int digit = user_input[0] - 48; // ASCII digits start at 48
         if (digit >= 0 && digit <= 9) {
            found = true;
            cout << numbers[digit] << '\n';
         }
      }

      for (int i = 0; i < numbers.size(); ++i) {
         if (user_input == numbers[i]) {
            cout << i << '\n';
            found = true;
            break;
         }
      }

      if (!found) {
         cout << "Unknown digit! Try again.";
      }


      cout << '\n' << "Please enter the digit to be converted: ";
   }
}
