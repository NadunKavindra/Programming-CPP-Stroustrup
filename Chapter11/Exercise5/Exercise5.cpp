/*
   Chapter 11 Exercise 5 Page 408
   Program that reads a string and outputs the "classification" of each character
*/

#include <iostream>
#include <string>

using namespace std;

void output_classification(ostream& os, const char ch)
{
   if (isspace(ch)) {
      os << "(whitespace)";
   }
   else if (isalpha(ch)) {
      os << "(letter)";
      if (isupper(ch)) {
         os << " (uppercase";
      }
      else {
         os << " (lowercase)";
      }
   }
   else if (isdigit(ch)) {
      os << "(digit)";
   }
   else if (isxdigit(ch)) {
      os << "(hexadecimal)";
   }
   else if (iscntrl(ch)) {
      os << "(control)";
   }
   else if (ispunct(ch)) {
      os << "(punctuation)";
   }
}

int main()
{
   string s;
   cout << "Enter a string to classify: ";
   getline(cin, s);

   for (const char ch : s) {
      cout << ch << ' ';
      output_classification(cout, ch);
      cout << '\n';
   }
}
