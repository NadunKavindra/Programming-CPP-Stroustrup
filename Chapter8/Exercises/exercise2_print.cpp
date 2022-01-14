/*
   Exercise 2 on Page 300
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

int main()
{
   vector<int> numbers {2, 4, 6, 8, 10};
   print(numbers, "TEST VALUES");
}
