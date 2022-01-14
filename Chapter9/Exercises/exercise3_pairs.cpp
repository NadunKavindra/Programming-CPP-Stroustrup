/*
   Exercise 3 on Page 339:
   Program from Exercise 2 on Page 339 modified to define <<, == and != operators
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
   void read_pairs(int n);
   void sort();

   friend ostream& operator<<(ostream& os, Name_Pairs p);
   friend bool operator==(const Name_Pairs& p1, const Name_Pairs& p2);
private:
   vector<string> names;
   vector<double> ages;
   
   void read_names(int n);
   void read_ages();
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

// Prompts the user to enter n number of (name, age) pairs
void Name_Pairs::read_pairs(int n)
{
   if (n <= 0) {
      error("invalid value. n must be a positive number");
   }
   read_names(n);
   read_ages();
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

ostream& operator<<(ostream& os, Name_Pairs p)
{
   for (int i {0}; i < p.names.size(); ++i) {
      os << '(' << p.names[i] << ", " << p.ages[i] << ")\n";
   }
   return os;
}

bool operator==(const Name_Pairs& p1, const Name_Pairs& p2)
{
   // definition of equality is not specified in the exercise description
   // Hence, I have decided to use the simpler approach to equality
   return p1.names == p2.names && p1.ages == p2.ages;
}

bool operator!=(const Name_Pairs& p1, const Name_Pairs& p2)
{
   return !(p1 == p2);
}

int main()
{
   Name_Pairs test;
   test.read_pairs(3);

   Name_Pairs sorted_test {test};
   sorted_test.sort();
   
   cout << "Unsorted:\n" << test;
   cout <<"\nSorted:\n" << sorted_test;
}