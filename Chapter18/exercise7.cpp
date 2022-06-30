/*
   Chapter 18 Exercise 7, Page 665

   Implement Chapter 18 Exercise 6 using C-style strings.
   Do not use standard library functions (I only used strlen)
*/

#include <iostream>
#include <string.h>    // Only for strlen

char* cat(const char* s1, const char* s2, const char* seperator)
{
   // +1 for terminator
   const size_t result_size = strlen(s1) + strlen(s2) + strlen(seperator) + 1;

   char* result = new char[result_size];

   while (*s1) {
      *result = *s1;
      ++s1;
      ++result;
   }

   while (*seperator) {
      *result = *seperator;
      ++seperator;
      ++result;
   }

   while (*s2) {
      *result = *s2;
      ++s2;
      ++result;
   }
   *result = 0;

   // Pointer to start of string
   return result - result_size + 1;
}

int main()
{
   char s1[] = "Bjarne";
   char s2[] = "Stroustrup";
   char seperator[] = "++";

   char* test = cat(s1, s2, seperator);
   char* test2 = cat("Hello", "World", " Cruel ");

   std::cout << test << '\n' << test2 << '\n';
}
