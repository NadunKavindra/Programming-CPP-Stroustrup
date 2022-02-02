/*
   Exercise 2 on Page 339:
   Program that implements a Name_pairs class holding (name, age) pairs
   where name is a string and age is a double. (as specified by exercise description)
*/

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

/// Returns the index of a string inside a vector
int find_index(const vector<string>& v, const string& s)
{
   if (v.empty()) {
      throw invalid_argument("cannot search empty vector");
   }

   auto i = find(v.begin(), v.end(), s);

   if (i == v.end()) {
      throw runtime_error(s + " not found");
   }
   return i - v.begin();
}

class Name_Pairs {
public:
   void read_names(int n);
   void read_ages();
   void sort();
   void print() const;

private:
   vector<string> names;
   vector<int> ages;
};

/// Prompts the user and reads n unique strings from cin
/// and adds them to the names member
void Name_Pairs::read_names(const int n)
{
   if (n <= 0) {
      throw invalid_argument("invalid value. n must be a positive number");
   }

   cout << "Please enter " << n << " unique names:\n";
   for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;

      // search vector for previous entries
      if (find(names.begin(), names.end(), s) != names.end()) {
         throw runtime_error(s + " has already been entered");
      }
      names.push_back(s);
   }
}

/// Prompts user to enter an age for each name in the member names
/// Reads the ages from cin
void Name_Pairs::read_ages()
{
   if (names.empty()) {
      throw invalid_argument("cannot add ages as names vector is empty");
   }

   for (string s : names) {
      int age = 0;
      cout << "Please enter the age of " << s << ": ";

      if (!(cin >> age) || age <= 0 || age > 120) {
         throw runtime_error("invalid input value for age");
      }
      ages.push_back(age);
   }
}

/// Prints out the (names[i], ages[i]) pairs to cout (one per line)
void Name_Pairs::print() const
{
   for (size_t i = 0; i < names.size(); ++i) {
      cout << '(' << names[i] << ", " << ages[i] << ")\n";
   }
}

/// Sorts the names member in alphabetical order and reorganizes the age member to
/// match
void Name_Pairs::sort()
{
   if (is_sorted(names.begin(), names.end())) {
      return;
   }

   vector<string> unsorted_names = names;
   std::sort(names.begin(), names.end());

   // After sorting the names, the correspoding age values will be in the incorrect
   // order Now we will fix the ordering of the values
   vector<int> unsorted_ages = ages;

   for (size_t i = 0; i < names.size(); ++i) {
      ages[i] = unsorted_ages[find_index(unsorted_names, names[i])];
   }
}

int main()
try {
   Name_Pairs test;
   test.read_names(5);
   cout << '\n';
   test.read_ages();
   cout << '\n';

   cout << "Before Sorting:\n";
   test.print();

   test.sort();
   cout << "\nAfter Sorting:\n";
   test.print();
}
catch (const exception& e) {
   cerr << "Error: " << e.what() << '\n';
}
catch (...) {
   cerr << "Error: unknown exception\n";
}