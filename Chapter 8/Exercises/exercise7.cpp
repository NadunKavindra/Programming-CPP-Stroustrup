/*
   Exercise 7 on Page 301
*/

#include "../../std_lib_facilities.h"

// Prompts the user to enter 5 unique names (using cin)
// Returns a vector containing the names
vector<string> get_names()
{
   vector<string> names;

   cout << "Please enter 5 unique names: ";
   for (int i {0}; i < 5; ++i) {
      string s;
      cin >> s;

      // search vector for previous entries
      if (find(names.begin(), names.end(), s) != names.end()) {
         error(s, " has already been entered");
      }
      names.push_back(s);
   }
   return names;
}

// Prompts the user to enter the ages corresponding to the names in v
// Returns a vector containing the age values
vector<int> get_ages(const vector<string>& v)
{
   vector<int> ages;
   for (string name : v) {
      int age {};
      cout << "Please enter the age of " << name << ": ";
      cin >> age;

      if (!cin || age <= 0 || age > 120) {
         error("invalid input value for age");
      }
      ages.push_back(age);
   }

   return ages;
}

// Finds the index of a string inside a vector
int find_index(const vector<string>& v, const string& s)
{
   if (v.empty()) {
      error("cannot search empty vector");
   }

   auto i { find(v.begin(), v.end(), s) };
   
   if (i == v.end()) {
      error(s, " not found");
   }
   return i - v.begin();
}

// Sorts the names and fixes the order of the values accordingly
void sort_names_values(vector<string>& names, vector<int>& values)
{
   if (names.size() != values.size()) {
      error("name and age vectors must have the same size");
   }

   if (is_sorted(names.begin(), names.end())) {
      return;
   }
   vector<string> unsorted_names {names};
   sort(names.begin(), names.end());

   // After sorting the names, the correspoding age values will be in the incorrect order
   // Now we will fix the ordering of the values
   vector<int> unsorted_ages {values};

   for (int i {0}; i < names.size(); ++i) {
      values[i] = unsorted_ages[find_index(unsorted_names, names[i])];
   }
}

// prints the (name, value) pairs to cout
void print_pairs(const vector<string>& names, const vector<int>& values)
{
   for (int i {0}; i < names.size(); ++i) {
      cout << "(" << names[i] << ", " << values[i] << ")\n";
   }
}

int main()
try {
   vector<string> names {get_names()};
   vector<int> ages {get_ages(names)};
   cout << "BEFOR SORTING:\n";
   print_pairs(names, ages);
   cout << '\n';

   sort_names_values(names, ages);
   cout << "AFTER SORTING:\n";
   print_pairs(names, ages);
}
catch (exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Error: unknown exception\n";
   return 2;
}
