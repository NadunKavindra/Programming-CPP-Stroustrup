/*
   Exercise 12 on Page 301:
   Modified the function print_until_s from Chapter 8.5.2
*/

#include <exception>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// Prints contents of a vector to cout until a certain string is reached
/// Originally written by Bjarne Stroustrup
void print_until_s(const vector<string>& v,const string& quit)
{
   for (const string s : v) {
      if (s == quit) {
         return;
      }
      cout << s << '\n';
   }
}

/// Prints contents of a vector to cout until
/// the second occurence of a certain string
void print_until_ss(const vector<string>& v, const string& quit)
{
   int counter = 0;
   for (const string s : v) {
      if (s == quit) {
         if (++counter == 2) {
            return;
         }
      }
      cout << s << '\n';
   }
}

int main()
try {
   const vector<string> test_values {"greetings", "traveller", "how", "goes",
                                     "it",        "how",       "are", "you"};

   print_until_s(test_values, "how");
   cout << '\n';
   print_until_ss(test_values, "how");

   return 0;
}
catch (const exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Error: unknown exception\n";
   return 2;
}
