/*
   Chapter 18 Exercise 2, Page 664

   Write a function that finds the first occurence of the C-style string x in s
   Do not use any standard library functions.
   Do not use subscripting.
*/
#include <exception>
#include <iostream>

bool starts_with(const char* s, const char* s2)
{
   while (*s2 && *s == *s2) {
      ++s;
      ++s2;
   }
   return *s2 == 0;
}

const char* findx(const char* s, const char* x)
{
   while (*s) {
      if (starts_with(s, x)) { return s; }
      ++s;
   }
   return nullptr;
}

int main()
try {
   char s[] = "Hello World";
   char x[] = "orld";

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
