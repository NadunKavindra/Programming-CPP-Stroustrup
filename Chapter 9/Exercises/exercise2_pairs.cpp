/*
   Exercise 2 on Page 339:
   Program that implements a Name_pairs class holding (name, age) pairs
   where name is a string and age is a double. (as specified by exercise description)
*/

#include "../../std_lib_facilities.h"

// Returns the index of a string inside a vector
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

class Name_Pairs {
public:
   void read_names(int n);
   void read_ages();
   void sort();
   void print() const;
private:
   vector<string> names;
   vector<double> ages;
};

// Prompts the user and reads n unique strings from cin 
// and adds them to the names member
void Name_Pairs::read_names(int n)
{
   if (n <= 0) {
      error("invalid value. n must be a positive number");
   }
   cout << "Please enter " << n << " unique names: ";
   for (string s; n > 0; --n) {
      cin >> s;

      // search vector for previous entries
      if (find(names.begin(), names.end(), s) != names.end()) {
         error(s, " has already been entered");
      }
      names.push_back(s);
   }
}

// Prompts user to enter an age for each name in the member names
// Reads the ages from cin
void Name_Pairs::read_ages()
{
   if (names.empty()) {
      error("cannot add ages as names vector is empty");
   }
   
   for (string s : names) {
      int age {};
      cout << "Please enter the age of " << s << ": ";
      cin >> age;

      if (!cin || age <= 0 || age > 120) {
         error("invalid input value for age");
      }
      ages.push_back(age);
   }
}

// Prints out the (names[i], ages[i]) pairs to cout (one per line)
void Name_Pairs::print() const
{
   if (names.empty() || ages.empty()) {
      error("cannot print as the names or the ages vector is empty");
   }

   for (int i {0}; i < names.size(); ++i) {
      cout << '(' << names[i] << ", " << ages[i] << ")\n"; 
   }
}

// Sorts the names member in alphabetical order and reorganizes the age member to match
void Name_Pairs::sort()
{
   if (is_sorted(names.begin(), names.end())) {
      return;
   }
   vector<string> unsorted_names {names};
   std::sort(names.begin(), names.end());

   // After sorting the names, the correspoding age values will be in the incorrect order
   // Now we will fix the ordering of the values
   vector<double> unsorted_ages {ages};

   for (int i {0}; i < names.size(); ++i) {
      ages[i] = unsorted_ages[find_index(unsorted_names, names[i])];
   }
}

int main()
try {
   Name_Pairs test;
   test.read_names(5);
   test.read_ages();

   cout << "Before Sorting:\n";
   test.print();

   test.sort();
   cout << "\nAfter Sorting:\n";
   test.print();
}
catch(exception& e) {
   cerr << "Error: " << e.what() << '\n';
}
catch (...) {
   cerr << "Error: unknown exception\n";
}

