/**
   Exercise 3 on Page 300
   @file exercise3_fibonacci.cpp
   @author Mustafa Adaoglu
*/

#include "../../std_lib_facilities.h"

/**
   Prints a vector of ints to cout
   @param v the vector to be printed
   @param label used as a "heading" in the output
*/ 
void print(const vector<int>& v, string label)
{
   cout << label << ": " << "{ ";

   for (int i { 0 }; i < v.size(); ++i) {
      cout << v[i];

      if (i != v.size() - 1) {
         cout << ", ";
      }
   }
   cout << " }" << '\n';
}

/**
   Fills an empty vector with a Fibonacci sequence
   @param x first element of the Fibonacci sequence
   @param y second element of the Fibonacci sequence
   @param n number of elements to filled into the vector
   @param v empty vector to be filled
 
*/
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
      int c { y };
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
