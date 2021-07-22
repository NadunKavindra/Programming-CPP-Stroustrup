/*
   Solution for Exercise 9 Chapter 3 on Page 86

   Converts spelled out numbers such as "zero" and "two" into digits
   Only works for digits 0-4 (for now)
*/

#include "../../std_lib_facilities.h"

int main()
{
   string user_input;
   cout << "Please enter an integer (using letters): ";

   while (cin >> user_input) {
      if (user_input == "zero") {
         cout << "\"" << user_input << "\" == 0\n";
      }
      else if (user_input == "one") {
         cout << "\"" << user_input << "\" == 1\n";
      }
      else if (user_input == "two") {
         cout << "\"" << user_input << "\" == 2\n";
      }
      else if (user_input == "three") {
         cout << "\"" << user_input << "\" == 3\n";
      }
      else if (user_input == "four") {
         cout << "\"" << user_input << "\" == 4\n";
      }
      else {
         cout << "\"" << user_input << "\"" << " is not a number I know\n";
      }

      cout << "Please enter another integer (using letters): ";
   }

}
