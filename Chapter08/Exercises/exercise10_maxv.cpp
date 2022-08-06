/*
   Exercise 10 on Page 301
*/

#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// @returns the largest element of a vector
double maxv(const vector<double>& v)
{
   if (v.empty()) {
      invalid_argument("cannot search an empty vector");
   }

   double max = v[0];
   for (size_t i = 1; i < v.size(); ++i) {
      if (v[i] > max) {
         max = v[i];
      }
   }
   return max;
}

/// Prints a vector of doubles to cout
/// @param label used as a "heading" in the output
void print_vector(const vector<double>& v, const string& label)
{
   cout << label << " == " << "{ ";

   for (size_t i = 0; i < v.size(); ++i) {
      cout << v[i];

      if (i != v.size() - 1) {
         cout << ", ";
      }
   }
   cout << " }" << '\n';
}

int main()
try {
   vector<double> test_values {1.0, 2.5, 4.89, 4.95, -5.54, -0.5};

   print_vector(test_values, "VALUES");

   cout << "MAXIMUM VALUE == " << maxv(test_values) << '\n';
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
