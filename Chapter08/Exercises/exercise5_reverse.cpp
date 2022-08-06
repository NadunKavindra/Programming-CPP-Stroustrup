/*
   Exercise 5 on Page 300
*/

#include <stdexcept>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/// prints a vector of ints to cout
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

/// Using pass by value
/// @returns the reverse of the provided vector
vector<int> reverse(vector<int> v)
{
   vector<int> result;
   for (int i = v.size() - 1; i >= 0; --i) {
      result.push_back(v[i]);
   }
   return result;
}

/// Reverses the order of elements of provided vector using pass by reference
void reverse_by_ref(vector<int>& v)
{
   // swap values from the outside in
   for (size_t i = 0; i < v.size() / 2; ++i) {
      swap(v[i], v[v.size() - 1 - i]);
   }
}

int main()
try {
   vector<int> test_values {1, 2, 3, 5, 7, 9};
   print_vector(test_values, "TEST VALUES");

   print_vector(reverse(test_values), "REVERSED using pass by value");

   reverse_by_ref(test_values);
   print_vector(test_values, "TEST VALUES REVERSED using pass by reference");

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
