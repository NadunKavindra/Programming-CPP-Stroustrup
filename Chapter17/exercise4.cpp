/*
   Chapter 17 Exercise 4, Page 624

   Write a function, char* strdup(const char*), that copies a C-style string into
   memory it allocates on the free store.
   Do not use any library functions.
*/

#include <iostream>

int my_strlen(const char* const s)
{
   int i = 0;
   while (s[i] != 0) {
      ++i;
   }
   return i;
}

char* my_strdup(const char* const s)
{
   const int size = my_strlen(s) + 1; // +1 for null terminator
   char* duplicate = new char[size];

   for (int i = 0; i < size; ++i) {
      duplicate[i] = s[i];
   }
   return duplicate;
}

int main()
{
   const char original[] = "Hello Traveller";
   std::cout << "Original: " << original << '\n';
   char* duplicate = my_strdup(original);
   std::cout << "Duplicate: " << duplicate << '\n';
}
