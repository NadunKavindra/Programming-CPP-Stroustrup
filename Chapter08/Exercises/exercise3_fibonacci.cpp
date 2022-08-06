/*
   Exercise 3 on Page 300
*/

#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// Prints a vector of ints to cout
/// @param label used as a "heading" in the output
void print_vector(const vector<int>& v, const string& label)
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

/// Fills an empty vector with a Fibonacci sequence
/// @param x is the first element of the Fibonacci sequence
/// @param y is the second element of the Fibonacci sequence
/// @param n is the number of elements to filled into the vector
/// @param v is the empty vector to be filled
void fibonacci(int x, int y, int n, vector<int>& v)
{
   if (n <= 0) {
      invalid_argument("n must be a positive number");
   }

   // exercise description states that v should be empty
   if (!v.empty()) {
      invalid_argument("v must be an empty vector");
   }

   do {
      v.push_back(x);
      int c = y;
      y = x + y;
      x = c;
      --n;
   } while (n > 0);
}

int main()
try {
   vector<int> test;
   fibonacci(1, 2, 7, test);

   print_vector(test, "RESULTS");
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
