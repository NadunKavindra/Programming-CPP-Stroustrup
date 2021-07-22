/*
   Exercise 9 on Page 171

   Modified the program from Exercise 8 (on Page 170)
   Writes out an error if the result cannot be represented as an int

   I am not exactly sure about the test values that would result in an overflow
   Hence, I have not been able to test the program properly.
   However, I believe the check_overflow function does what the exercise asks for.
   (I can only "believe" without proper testing...)
*/

#include "../../std_lib_facilities.h"

bool check_overflow(vector<int> integers, int n, int sum)
{
   for (int i = 0; i < n; ++i)
      sum -= integers[i];
   
   if (sum == 0)  // no overflow
      return false; 
   
   return true;
}

int main()
try {
   int n = 0;
   cout << "Please enter the number of values that you want to sum: ";
   cin >> n;

   if (n < 1)
      error("The numbers of values to be summed must be a positive integer.");

   vector<int> integers;
   int input;

   cout << "Please enter some integers (enter '|' to stop): ";
   while (cin >> input)
      integers.push_back(input);

   if (n > integers.size())
      error("There are not enough numbers in the series");

   int sum = 0;
   for (int i = 0; i < n; ++i)
      sum += integers[i];

   if (check_overflow(integers, n, sum))
      error("The result cannot be represented as an int");
   
   cout << "The sum of the first " << n << " numbers ( ";
   for (int i = 0; i < n; ++i)
      cout << integers[i] << ' ';

   cout << ") is " << sum << '\n';

   return 0;
}
catch (exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Oops: unknown exception!\n";
   return 2;
}
