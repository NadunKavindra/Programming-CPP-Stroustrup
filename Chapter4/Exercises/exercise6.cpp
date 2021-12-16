/*
   Exercise 6 on Page 128-129

   Converts a digit to its corresponding spelled-out value and vice versa
*/

#include "../../std_lib_facilities.h"

int main()
{
   const vector<string> numbers {"zero", "one", "two",   "three", "four",
                                 "five", "six", "seven", "eight", "nine"};

   cout << "Please enter the digit to be converted (enter '|' to exit): ";

   for (string input; cin >> input && input != "|";) {
      bool found = false;

      if (input.size() == 1) {
         const int digit = input[0] - 48; // ASCII digits start at 48

         if (digit >= 0 && digit <= 9) {
            found = true;
            cout << numbers[digit] << '\n';
         }
      }

      for (size_t i = 0; i < numbers.size(); ++i) {
         if (input == numbers[i]) {
            cout << i << '\n';
            found = true;
            break;
         }
      }

      if (!found) {
         cout << "Unknown digit! Try again.\n";
      }

      cout << '\n'
           << "Please enter the digit to be converted (enter '|' to exit): ";
   }
}
