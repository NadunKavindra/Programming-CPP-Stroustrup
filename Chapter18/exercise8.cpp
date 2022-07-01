/*
   Chapter 18 Exercise 8, Page 665

   Modified the code in 18.7 to use the approach of making a backward copy to
   check if a string is a palindrome.
   Using both std::string and C-style string
*/

#include <algorithm>
#include <iostream>
#include <string.h>
#include <string>

std::string reverse(const std::string& s)
{
   return std::string{s.rbegin(), s.rend()};
}

bool is_palindrome(const std::string& s) { return s == reverse(s); }

/// @warning The returned string is allocated on the free store
///          and must be freed/deleted when appropriate.
char* reverse(const char* s)
{
   const size_t s_length = strlen(s);
   char* result = new char[s_length + 1];
   std::reverse_copy(s, s + s_length, result);
   *(result + s_length) = 0;
   return result;
}

bool is_palindrome(const char* s)
{
   const char* backwards = reverse(s);
   const bool result = strcmp(s, backwards) == 0;
   delete[] backwards;
   return result;
}

int main()
{
   const std::string test = "home";
   std::cout << test << " is";
   if (!is_palindrome(test)) {
      std::cout << " not";
   }
   std::cout << " a palindrome\n";

   const char test2[] = "anna";
   std::cout << test2 << " is";
   if (!is_palindrome(test2)) {
      std::cout << " not";
   }
   std::cout << " a palindrome\n";
}
