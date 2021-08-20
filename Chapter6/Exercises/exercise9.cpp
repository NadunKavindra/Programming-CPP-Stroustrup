/*
   Exercise 9 on Page 219

   Program that reads digits and composes them into integers.
   Refer to exercise description for more details

   For example the number 123 is read as 1, 2, 3
*/

#include "../../std_lib_facilities.h"

// Converts a vector of chars into it's integer representation
// Only works with positive collection of digits
// e.g. {'1', '2', '3', '4'} into 1234
int chars_to_int(vector<char> digits)
{
   if (digits[0] == '-') {
      error("cannot process negative numbers");
   }

   if (digits.size() == 1) {
      return digits[0] - '0';    // 'x' - '0' == x by ASCII Code conventions
   }

   int result { 0 };
   int multiplier = pow(10, digits.size() - 1);

   for (char digit : digits) {
      result += (digit - '0') * multiplier;   // 'x' - '0' == x by ASCII Code conventions
      multiplier /= 10;
   }

   return result;
}

// Prints out the number along with it's constituents
// Parameter must be a non-negative number.
void print_number(int number)
{
   if (number < 0) {
      error("cannot process negative numbers");
   }

   if (number == 0) {
      cout << number << " is zero\n";
      return;
   }

   // start printing the number
   cout << number << " is ";

   int scale { 1000 };   // 1000 as a number can have a maximum of 4 digits

   while (scale >= 1) {
      int digit { number / scale };

      if (digit != 0) {
         switch (scale) {
         case 1000:
            cout << digit << " thousand(s)";
            break;
         case 100:
            cout << digit << " hundred(s)";
            break;
         case 10:
            cout << digit << " tens(s)";
            break;
         case 1:
            cout << digit << " one(s)";
            break;
         }

         number %= scale;
         if (number != 0) {   // there are still numbers remaining
            cout << " and ";
         }
      }
      scale /= 10;
   }
   cout << '\n';
}

int main()
try {
   vector<char> digits;

   while (digits.empty()) {
      cout << "Please enter a number with at most 4 digits: ";

      while (true) {
         char tmp = getchar();
         if (!isdigit(tmp)) {
            cin.ignore(120, '\n');  // ignore remaining chars in the buffer
            digits.clear();
            break;
         }

         if (tmp == '\n') {
            if (digits.size() > 4) {
               digits.clear();
            }
            break;
         }

         digits.push_back(tmp);
      }
   }

   const int number { chars_to_int(digits) };

   print_number(number);
}
catch (exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Error: unknown exception\n";
   return 2;
}
