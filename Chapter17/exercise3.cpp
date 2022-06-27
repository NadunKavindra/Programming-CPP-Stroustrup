/*
   Chapter 17 Exercise 3, Page 624

   Write a function, void to_lower(char* s) that replaces all uppercase characters to
   lowercase equivalent. Do not use any library functions.
*/

#include <iostream>

void to_lower(char* s)
{
   while (*s) {
      // if uppercase
      if (*s > 64 && *s < 91) {
         // Convert to lowercase using ASCII
         *s += 32;
      }
      ++s;
   }
}

int main()
{
   char s[] = "Hello WORLD";
   std::cout << s << '\n';
   to_lower(s);
   std::cout << s << '\n';
}
