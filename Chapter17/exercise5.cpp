/*
   Chapter 17 Exercise 5, Page 624
   Write a function, that finds the first occurence
   of the C-style string x in s
*/
#include <exception>
#include <iostream>

bool equals(const char* s, const char* s2)
{
   while (*s && *s2 && *s == *s2) {
      ++s;
      ++s2;
   }
   return *s2 == 0;
}

const char* findx(const char* s, const char* x)
{
   while (*s) {
      if (equals(s, x)) {
         return s;
      }
      ++s;
   }
   return nullptr;
}

int main()
try {
   char s[] = "Hello World";
   char x[] = "orl";

   std::cout << findx(s, x) << '\n';

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
