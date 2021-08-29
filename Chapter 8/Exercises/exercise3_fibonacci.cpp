/*
   Exercise 3 on Page 300
*/

#include "../../std_lib_facilities.h"

// Prints a vector of ints to cout
// label used as a "heading" in the output
void print(const vector<int>& v, string label)
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

// Fills an empty vector with a Fibonacci sequence
// x is the first element of the Fibonacci sequence
// y is the second element of the Fibonacci sequence
// n is the number of elements to filled into the vector
// v is the empty vector to be filled
void fibonacci(int x, int y, int n, vector<int>& v)
{
   if (n <= 0) {
      error("n must be a positive number");
   }

   // exercise description states that v should be empty
   if (!v.empty()) {
      error("v must be an empty vector");
   }

   do {
      v.push_back(x);
      int c {y};
      y = x + y;
      x = c;
      --n;
   } while (n > 0);
}

int main()
try {
   vector<int> test;
   fibonacci(1, 2, 7, test);

   print(test, "RESULTS");
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