/*
   Exercise 10 on Page 301
*/

#include "../../std_lib_facilities.h"

// finds the largest element of a vector
double maxv(const vector<double>& v)
{
   if (v.empty()) {
      error("cannot search an empty vector");
   }

   double max {v[0]};

   for (int i {1}; i < v.size(); ++i) {
      if (v[i] > max) {
         max = v[i];
      }
   }
   return max;
}

// Prints a vector of doubles to cout
// label used as a "heading" in the output
void print(const vector<double>& v, string label)
{
   cout << label << ": " << "{ ";

   for (int i {0}; i < v.size(); ++i) {
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

   print(test_values, "VALUES");

   cout << "MAXIMUM VALUE == " << maxv(test_values) << '\n';
}
catch (exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Error: unknown exception\n";
   return 2;
}
