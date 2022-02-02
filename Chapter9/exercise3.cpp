/*
   Exercise 3 on Page 339:
   Program that implements a Name_pairs class holding (name, age) pairs
   where name is a string and age is a int.
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

class NamePairs {
public:
   void read_names(int n);
   void read_ages();
   void sort();
   vector<string> get_names() const { return names; }
   vector<int> get_ages() const { return ages; }

private:
   vector<string> names;
   vector<int> ages;
};

/// Prompts the user and reads n unique strings from cin
/// and adds them to the names member
void NamePairs::read_names(const int n)
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
void NamePairs::read_ages()
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

/// Sorts the names member in alphabetical order and reorganizes the age member to
/// match
void NamePairs::sort()
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

ostream& operator<<(ostream& os, const NamePairs& pairs)
{
   vector<string> names = pairs.get_names();
   vector<int> ages = pairs.get_ages();
   for (size_t i = 0; i < names.size(); ++i) {
      os << '(' << names[i] << ',' << ages[i] << ")\n";
   }
   return os;
}

bool operator==(const NamePairs& p1, const NamePairs& p2)
{
   // Exercise description does not state how the equals should work
   // so I implemented the straightforward version
   return (p1.get_names() == p2.get_names()) && (p1.get_ages() == p2.get_ages());
}

bool operator!=(const NamePairs& p1, const NamePairs& p2)
{
   return !(p1 == p2);
}

int main()
try {
   NamePairs unsorted;
   unsorted.read_names(5);
   cout << '\n';
   unsorted.read_ages();
   cout << '\n';

   NamePairs sorted = unsorted;
   sorted.sort();

   cout << "sorted == unsorted ? " << (sorted == unsorted) << '\n';
   cout << "unsorted == unsorted ? " << (unsorted == unsorted) << '\n';
   cout << "sorted != sorted ? " << (sorted != sorted) << '\n';
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
