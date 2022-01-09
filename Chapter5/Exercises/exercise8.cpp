/*
   Exercise 8 on Page 170

   Reads and stores a series of integers
   Computes the sum of the first 'n' integers
*/

#include "../../std_lib_facilities.h"

/// Returns the sum of the first n elements of a vector
/// Throws an exception if there aren't enough elements in the vector
int sum_vector(const vector<int> v,const size_t n)
{
   if (n > v.size()) {
      error("There are not enough numbers to sum");
   }

   int sum = 0;
   for (size_t i = 0; i < n; ++i) {
      sum += v[i];
   }

   return sum;
}

void run_exercise()
{
   int n = 0;
   cout << "Please enter the number of values that you want to sum: ";

   if (!(cin >> n) || n < 1) {
      error("The numbers of values to be summed must be a positive integer.");
   }

   vector<int> integers;

   cout << "Please enter some integers (enter any character to stop): ";
   for (int input = 0; cin >> input; ) {
      integers.push_back(input);
   }

   cout << '\n' << "The sum of the first " << n << " numbers ( ";
   for (int i = 0; i < n; ++i) {
      cout << integers[i] << ' ';
   }
   cout << ") is " << sum_vector(integers, n) << '\n';
}

int main()
try {
   run_exercise();
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
