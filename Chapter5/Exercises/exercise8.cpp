/*
   Exercise 8 on Page 170

   Reads and stores a series of integers
   Computes the sum of the first 'n' integers
*/

#include "../../std_lib_facilities.h"

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
