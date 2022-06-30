/*
   Chapter 18 Exercise 5, Page 665

   Write a function that concatenates two string with a dot in between
*/

#include <string>
#include <iostream>

std::string cat_dot(const std::string& s1, const std::string& s2)
{
   return s1 + '.' + s2;
}

int main()
{
   std::cout << cat_dot("Niels", "Bohr");
}
