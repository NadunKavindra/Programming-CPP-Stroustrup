/*
   Chapter 18 Exercise 1, Page 664

   Write a function, char* strdup(const char*) that copies a C-style string into
   memory it allocates on the free store. Do not use standard library functions.
   Do not use subscripting.
*/

#include <exception>
#include <iostream>

int my_strlen(const char* s)
{
   int length = 0;
   while (*(s + length)) { ++length; }
   return length;
}

char* my_strdup(const char* s)
{
   const int size = my_strlen(s) + 1; // +1 for null terminator
   char* duplicate = new char[size];

   for (int i = 0; i < size; ++i) { *(duplicate + i) = *(s + i); }
   return duplicate;
}

int main()
{
   char original[] = "Hello Traveller";
   std::cout << "Original: " << original << '\n';

   char* duplicate = my_strdup(original);
   std::cout << "Duplicate: " << duplicate << '\n';
}
