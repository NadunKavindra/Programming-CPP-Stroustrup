/*
   Exercise 11 on Page 301
*/

#include "../../std_lib_facilities.h"

// Prints a vector of doubles to cout
// label used as a "heading" in the output
void printv(const vector<double>& v, string label)
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

// finds the largest element of a vector (of doubles)
double maxv(const vector<double>& v)
{
   if (v.empty()) {
      error("cannot search an empty vector for max value");
   }
   double max {v[0]};

   for (int i {1}; i < v.size(); ++i) {
      if (v[i] > max) {
         max = v[i];
      }
   }
   return max;
}

// finds the smallest element of a vector (of doubles)
double minv(const vector<double>& v)
{
   if (v.empty()) {
      error("cannot search an empty vector for min value");
   }
   double min {v[0]};

   for (int i {0}; i < v.size(); ++i) {
      if (v[i] < min) {
         min = v[i];
      }
   }
   return min;
}

// Calculates the mean of a vector (of doubles)
double meanv(const vector<double>& v)
{
   if (v.empty()) {
      error("cannot calculate mean of an empty vector");
   }
   double sum {};

   for (double d : v) {
      sum += d;
   }
   return sum / v.size();
}

// Finds the median element of a vector (of doubles)
double medianv(vector<double> v)
{
   if (v.empty()) {
      error("cannot find median of empty vector");
   }

   unsigned int n {v.size() / 2};
   nth_element(v.begin(), v.begin() + n, v.end());

   if (v.size() % 2 == 0) {
      nth_element(v.begin(), v.begin() + n + 1, v.end());
      return (v[n] + v[n - 1]) / 2;
   }
   return v[n];
}

struct statistics {
   double minimum;
   double maximum;
   double mean;
   double median;
};

// Finds the smallest, the largest, the median element and the mean of a vector
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
   vector<double> test_values {7, 3, 6, 5};
   statistics results {compute_stats(test_values)};

   printv(test_values, "VALUES");
   cout << "Smallest == " << results.minimum << '\n';
   cout << "Largest == " << results.maximum << '\n';
   cout << "Mean == " << results.mean << '\n';
   cout << "Median == " << results.median << '\n';

   return 0;
}
catch (exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Error: unknown exception\n";
   return 2;
}
