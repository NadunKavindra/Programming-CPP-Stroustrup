/*
   Exercise 10 on Page 170

   Modified the program from Exercise 8 (on Page 170)
   Uses double values instead of int
   Also computes the difference between adjacent values into a vector
   Writes out the vector containing the differences
*/

#include "../../std_lib_facilities.h"

/// Returns the sum of the first n elements of a vector
/// Throws an exception if there aren't enough elements in the vector
double sum_vector(const vector<double> v, const size_t n)
{
   if (n > v.size()) {
      error("there are not enough numbers to process the summation");
   }

   double sum = 0;
   for (size_t i = 0; i < n; ++i) {
      sum += v[i];
   }

   return sum;
}

// returns a vector containing the n-1 differences between adjacent values of the
// provided vector
vector<double> diff_vector(const vector<double> v, const size_t n)
{
   if (n > v.size()) {
      error("insufficient amount of numbers to process");
   }

   vector<double> differences;
   for (size_t i = 0; i < n - 1; ++i) {
      differences.push_back(v[i + 1] - v[i]);
   }

   return differences;
}

void run_exercise()
{
   int n = 0;
   cout << "Please enter the number of values that you want to sum: ";

   if (!(cin >> n) || n < 1) {
      error("The numbers of values to be summed must be a positive integer.");
   }

   vector<double> numbers;

   cout << "Please enter some double values (enter any character to stop): ";
   for (double input = 0; cin >> input; ) {
      numbers.push_back(input);
   }

   cout << "The sum of the first " << n << " numbers ( ";
   for (int i = 0; i < n; ++i) {
      cout << numbers[i] << ' ';
   }
   cout << ") is " << sum_vector(numbers, n) << '\n';

   cout << "\nThe differences between the first " << n << " adjacent values are: ";
   for (double difference : diff_vector(numbers, n)) {
      cout << difference << ' ';
   }
   cout << '\n';
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
