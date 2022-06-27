/*
   Chapter 17 Exercise 7, Page 624

   Please note that I'm still experimenting with doc comments
*/

#include <exception>
#include <iostream>
#include <stdexcept>

/// @brief Reads individual characters (including whitespace) until the stop
/// character is encountered or n characters are read
/// @param is input stream to read from
/// @param s the character array to fill
/// @param stop the character at which the read is stopped
/// @param size the size of the array
void read_until(std::istream& is, char* s, const char stop, const int size)
{
   if (s == nullptr) {
      throw std::invalid_argument("read_until --> arg s is nullptr");
   }

   char ch = 0;

   // Exercise description states "read individual characters"
   for (int i = 0; is.get(ch); ++i) {
      if (ch == stop || i == size) {
         is.putback(ch);
         s[i] = 0;
         return;
      }
      s[i] = ch;
   }
}

int main()
try {
   constexpr int LENGTH = 100;
   constexpr char END = '!';

   char array[LENGTH];

   read_until(std::cin, array, END, LENGTH);
   std::cout << array << '\n';
   return 0;
}
catch (const std::exception& e) {
   std::cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   std::cerr << "Error: unknown exception";
   return 2;
}
