/*
   Exercise 10 on Page 170

   Modified the program from Exercise 8 (on Page 170)
   Uses double values instead of int
   Also computes the difference between adjacent values into a vector
   Writes out the vector containing the differences
*/

#include "../../std_lib_facilities.h"

int main()
try {
   int n = 0;
   cout << "Please enter the number of values that you want to sum: ";
   cin >> n;

   if (n < 1)
      error("The numbers of values to be summed must be a positive integer.");

   vector<double> series;
   double input;

   cout << "Please enter some double values (enter '|' to stop): ";
   while (cin >> input)
      series.push_back(input);

   if (n > series.size())
      error("There are not enough numbers in the series");

   double sum = 0;
   for (int i = 0; i < n; ++i)
      sum += series[i];

   cout << "The sum of the first " << n << " numbers ( ";
   for (int i = 0; i < n; ++i)
      cout << series[i] << ' ';

   cout << ") is " << sum << '\n';

   vector<double> differences;
   for (int i = 0; i < n - 1; ++i)
      differences.push_back(series[i + 1] - series[i]);

   cout << "The differences between adjacent values are: ";
   for (double difference : differences)
      cout << difference << ' ';

   cout << '\n';
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
