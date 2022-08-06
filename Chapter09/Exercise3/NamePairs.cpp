#include "NamePairs.h"

#include <iostream>
#include <string>
#include <algorithm>

void NamePairs::read_names()
{
   std::string name;

   std::cout << "Enter a name to be stored or -1 to stop: ";
   while (std::cin >> name && name != "-1") {
      names.push_back(name);
      std::cout << "\nEnter another name to be stored or -1 to stop: ";
   }
}

void NamePairs::read_ages()
{
   for (size_t i = 0; i < names.size(); ++i) {
      std::cout << "Please enter the age of " + names[i] + ": ";
      int age = 0;

      if (! (std::cin >> age) || age < 1) {
         throw std::runtime_error("Age value must be a positive integer");
      }
      ages.push_back(age);

      if (i != names.size() -1) {  // if not the last element
         std::cout << '\n';
      }
   }
}

/// @returns the index of s inside of v
/// @returns -1 if s is not inside of v
static int find_index(std::vector<std::string> v, std::string s)
{
   const auto i = find(v.begin(), v.end(), s);
   if (i == v.end()) {
      return -1;
   }

   return i - v.begin();
}

void NamePairs::sort()
{
   // Make copies to be used when sorting ages
   const std::vector<std::string> unsorted_names = names;
   const std::vector<int> unsorted_ages = ages;

   std::sort(names.begin(), names.end());

   for (size_t i = 0; i < ages.size(); ++i) {
      ages[i] = unsorted_ages[find_index(unsorted_names, names[i])];
   }
}

std::ostream &operator<<(std::ostream &os, const NamePairs &np) {
   const std::vector<std::string>& names = np.get_names();
   const std::vector<int>& ages = np.get_ages();

   for (size_t i = 0; i < names.size(); ++i) {
      os << '(' << names[i] << ", " << ages[i] << ')';

      if (i != names.size() -1) {  // if not the last element
         std::cout << '\n';
      }
   }
   return os;
}
