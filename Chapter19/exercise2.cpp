/*
   Chapter 19 Exercise 2, Page 708

   Write a template function that takes a vector<T> vt and a vector<U> vu as
   arguments and return the sum of all vt[i] * vu[i].
*/

#include <iostream>
#include <stdexcept>
#include <vector>

template<typename T, typename U>
auto sum_of_products(const std::vector<T>& vt, const std::vector<U>& vu)
{
   if (vt.size() != vu.size()) {
      throw std::invalid_argument(
          "sum_of_products() -> argument vectors must have the same size");
   }

   // determine type by performing an initial calculation
   auto result = vt[0] * vu[0];

   for (size_t i = 1; i < vt.size(); ++i) {
      result += vt[i] * vu[i];
   }
   return result;
}

int main()
try {
   std::vector<int> vi = {1, 2, 3, 4};
   std::vector<double> vd = {1.5, 2.5, 2.5, 4.0};

   std::cout << sum_of_products(vi, vd) << '\n';
   return 0;
}
catch (const std::exception& e) {
   std::cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   std::cerr << "Error: unknown exception\n";
   return 2;
}
