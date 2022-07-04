/*
   Chapter 19 Exercise 1, Page 708

   Write a template function f() that adds the elemnt of one vector<T> to the
   elements of another (v1[i] += v2[i])
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
   os << '{';
   for (size_t i = 0; i < v.size(); ++i) {
      os << v[i];
      if (i < v.size() - 1) {
         os << ", ";
      }
   }
   return os << '}';
}

template<typename T>
void f(std::vector<T>& v1, const std::vector<T>& v2)
{
   if (v1.size() != v2.size()) {
      throw std::invalid_argument(
          "f() -> argument vectors must have same size");
   }

   for (size_t i = 0; i < v1.size(); ++i) {
      v1[i] += v2[i];
   }
}

int main()
try {
   std::vector<int> v1 = {1, 2, 3, 4};
   std::vector<int> v2 = {5, 6, 7, 8};

   std::vector<std::string> vs1 = {"hello ", "how "};
   std::vector<std::string> vs2 = {"world", "are you"};

   f(v1, v2);
   f(vs1, vs2);

   std::cout << v1 << '\n' << vs1 << '\n';

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
