/*
   Chapter 11 Exercise 10 Page 409
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/// @returns a vector of whitespace seperated substrings of the argument s
std::vector<std::string> split(const std::string& s)
{
   std::vector<std::string> split;

   if (s.length() != 0) {
      std::istringstream stream{s};
      for (std::string substring; stream >> substring; split.push_back(substring))
         ;
   }
   return split;
}

int main()
{
   const std::string test = "Hello World Let's Try This";

   std::vector<std::string> vs = split(test);

   for (const std::string& s : vs) {
      std::cout << s << '\n';
   }
}
