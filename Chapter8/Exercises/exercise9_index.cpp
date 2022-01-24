/*
   Exercise 9 on Page 301
*/

#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

/// @returns an "index" which is the sum of all a[i] * b[i]
double calculate_index(const vector<double>& a, const vector<double>& b)
{
   if (a.size() != b.size()) {
      invalid_argument("both vectors must have the same size");
   }

   double index = 0;
   for (size_t i = 0; i < a.size(); ++i) {
      index += a[i] * b[i];
   }
   return index;
}

int main()
try {
   vector<double> weight {10, 20, 30, 40};
   vector<double> price {2, 4, 6, 8};

   cout << "index == " << calculate_index(weight, price) << '\n';
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