/*
   Exercise 8 on Page 170

   Reads and stores a series of integers
   Computes the sum of the first 'n' integers
*/

#include "../../std_lib_facilities.h"

// returns the sum of the first n elements of a vector
int sum_vector(vector<int> v, int n)
{
   if (n > v.size()) {
      error("There are not enough numbers to sum");
   }

   int sum { 0 };
   for (int i { 0 }; i < n; ++i) {
      sum += v[i];
   }

   return sum;
}

int main()
try {
   int n {};
   cout << "Please enter the number of values that you want to sum: ";
   cin >> n;

   if (!cin || n < 1) {
      error("The numbers of values to be summed must be a positive integer.");
   }

   vector<int> integers;

   cout << "Please enter some integers (enter any character to stop): ";
   for (int input {}; cin >> input; ) {
      integers.push_back(input);
   }

   int sum { sum_vector(integers, n) };

   cout << '\n' << "The sum of the first " << n << " numbers ( ";
   for (int i { 0 }; i < n; ++i) {
      cout << integers[i] << ' ';
   }
   cout << ") is " << sum << '\n';
}
catch (exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Oops: unknown exception!\n";
   return 2;
}
