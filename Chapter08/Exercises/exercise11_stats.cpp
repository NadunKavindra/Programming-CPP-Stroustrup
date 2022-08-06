/*
   Exercise 11 on Page 301
*/

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

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

/// @returns the largest element of a (unsorted) vector
double maxv(const vector<double>& v)
{
   if (v.empty()) {
      invalid_argument("cannot search an empty vector for max value");
   }

   double max = v[0];
   for (size_t i = 1; i < v.size(); ++i) {
      if (v[i] > max) {
         max = v[i];
      }
   }
   return max;
}

/// @returns the smallest element of a (unsorted) vector
double minv(const vector<double>& v)
{
   if (v.empty()) {
      invalid_argument("cannot search an empty vector for min value");
   }

   double min = v[0];
   for (size_t i = 1; i < v.size(); ++i) {
      if (v[i] < min) {
         min = v[i];
      }
   }
   return min;
}

/// @returns the mean of a vector
double meanv(const vector<double>& v)
{
   if (v.empty()) {
      invalid_argument("cannot calculate mean of an empty vector");
   }

   double sum = 0;
   for (const double d : v) {
      sum += d;
   }
   return sum / v.size();
}

/// @returns the median element of a vector
double medianv(vector<double> v)
{
   if (v.empty()) {
      invalid_argument("cannot find median of empty vector");
   }

   // values need to be sorted before computing median
   sort(v.begin(), v.end());

   size_t mid_index = v.size() / 2;
   if (v.size() % 2 == 0) {
      return (v[mid_index] + v[mid_index - 1]) / 2;
   }
   else {
      return v[mid_index];
   }
}

struct statistics {
   double minimum;
   double maximum;
   double mean;
   double median;
};

/// @returns struct containing the smallest, the largest,
/// the median and the mean of a vector
statistics compute_stats(const vector<double>& v)
{
   statistics result;
   result.minimum = minv(v);
   result.maximum = maxv(v);
   result.mean = meanv(v);
   result.median = medianv(v);

   return result;
}

int main()
try {
   vector<double> test_values {7.2, 3.4, 6.2, -5.3, -5.3, 0};
   statistics results = compute_stats(test_values);

   print_vector(test_values, "VALUES");
   cout << "Smallest == " << results.minimum << '\n';
   cout << "Largest == " << results.maximum << '\n';
   cout << "Mean == " << results.mean << '\n';
   cout << "Median == " << results.median << '\n';

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
