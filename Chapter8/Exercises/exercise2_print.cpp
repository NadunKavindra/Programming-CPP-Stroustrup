/*
   Exercise 2 on Page 300
*/

#include <iostream>
#include <string>
#include <vector>

/// Prints a vector of ints to cout
/// @param label used as a "heading" in the output
void print_vector(const std::vector<int>& v, const std::string& label)
{
   std::cout << label << " == " << "{ ";

   for (size_t i = 0; i < v.size(); ++i) {
      std::cout << v[i];

      if (i != v.size() - 1) {
         std::cout << ", ";
      }
   }
   std::cout << " }" << '\n';
}

int main()
{
   std::vector<int> numbers {2, 4, 6, 8, 10};
   print_vector(numbers, "TEST VALUES");
}
