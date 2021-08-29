/*
   Exercise 9 on Page 301
*/

#include "../../std_lib_facilities.h"

// Computes an "index" which is the sum of all a[i] * b[i]
double calculate_index(const vector<double>& a, const vector<double>& b)
{
   if (a.size() != b.size()) {
      error("both vectors must have the same size");
   }

   double index {};
   for (int i {0}; i < a.size(); ++i) {
      index += a[i] * b[i];
   }
   return index;
}

int main()
try {
   vector<double> weight {10, 20, 30, 40};
   vector<double> price {2, 4, 6, 8};

   cout << "index == " << calculate_index(weight, price) << '\n';
}
catch (exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Error: unknown exception\n";
   return 2;
}