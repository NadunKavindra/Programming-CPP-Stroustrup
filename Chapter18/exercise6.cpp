/*
   Chapter 18 Exercise 6, Page 665

   Modify cat_dot from previous exercise to take a string to be used
   as the seperator as it's third argument
*/

#include <iostream>
#include <string>

std::string cat(const std::string& s1, const std::string& s2,
                    const std::string& seperator)
{
   return s1 + seperator + s2;
}

int main()
{
   std::cout << cat("Niels", "Bohr", "->");
}
