/*
   Exercise 5 on Page 300
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

// Reverses the order of elements of the vector using pass by value
vector<int> reverse(const vector<int>& v)
{
   vector<int> result;

   for (const int element : v) {
      result.insert(result.begin(), element);
   }

   // alternatively
   // for (int i = v.size() - 1; i >= 0; --i) {
   //    result.push_back(v[i]);
   // }

   return result;
}

// Reverses the order of elements of provided vector using pass by reference
void reverse_by_ref(vector<int>& v)
{
   // swap values from the outside in
   for (int i {0}; i < v.size() / 2; ++i) {
      swap(v[i], v[v.size() - 1 - i]);
   }
}

int main()
try {
   vector<int> test_values {1, 2, 3, 5, 7, 9};
   print(test_values, "TEST VALUES");

   print(reverse(test_values), "REVERSED using pass by value");

   reverse_by_ref(test_values);
   print(test_values, "TEST VALUES REVERSED using pass by reference");

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
