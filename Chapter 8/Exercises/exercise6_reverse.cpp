/*
   Exercise 6 on Page 301: 
   Functions from Exercise 5 but with a vector<string> 
*/

#include "../../std_lib_facilities.h"

// Prints a vector of strings to cout
// label used as a "heading" in the output
void print(const vector<string>& v, string label)
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

// Reverses the order of elements of vector using pass by value
vector<string> reverse(const vector<string>& v)
{
   vector<string> result;

   for (const string s : v) {
      result.insert(result.begin(), s);
   }

   // alternatively
   // for (int i = v.size() - 1; i >= 0; --i) {
   //    result.push_back(v[i]);
   // }

   return result;
}

// Reverses the order of elements of the provided vector using pass 
// by reference
void reverse_by_ref(vector<string>& v)
{
   // swap values from the outside in
   for (int i {0}; i < v.size() / 2; ++i) {
      swap(v[i], v[v.size() - 1 - i]);
   }
}

int main()
try {
   vector<string> test_values {"hello", "there", "traveller!", "greetings"};

   print(test_values, "TEST VALUES");
   print(reverse(test_values), "REVERSED using pass by value");

   cout << '\n';
   print(test_values, "TEST VALUES");

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
