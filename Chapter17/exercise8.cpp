/*
   Chapter 17 Exercise 8, Page 624

   Same as Exercise 7, but using std::string
*/

#include <iostream>
#include <stdexcept>
#include <string>

/// @brief Reads individual characters (including whitespace) until the stop
/// character is encountered
/// @param is input stream to read from
/// @param s the string to write to
/// @param stop the character at which the read is stopped
void read_until(std::istream& is, std::string& s, const char stop)
{
   char ch = 0;

   // Exercise description states "read individual characters"
   while (is.get(ch)) {
      if (ch == stop) {
         is.putback(ch);
         return;
      }
      s.push_back(ch);
   }
}

int main()
try {
   constexpr char END = '!';

   std::string s;

   read_until(std::cin, s, END);
   std::cout << s << '\n';
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