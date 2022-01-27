/*
   Code from Chapter 7 of "Programming -- Principles and Practice Using C++"
   by Bjarne Stroustrup

   Modifications by m-adaoglu
   Please see main.cpp for more details
*/

#include "TokenStream.hpp"
#include "Token.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using std::cin;
using std::runtime_error;
using std::string;

Token TokenStream::get()
{
   if (full) { // check if we already have a Token ready
      full = false;
      return buffer; // remove token from buffer
   }

   char ch;
   do {
      ch = char(cin.get());
      if (ch == '\n') {
         return Token{ENTER_KEY};
      }
   } while (isspace(ch));

   switch (ch) {
   // let each character represent itself
   case '!':
   case '(':
   case ')':
   case '{':
   case '}':
   case '+':
   case '-':
   case '*':
   case '/':
   case '%':
   case '=':
   case ',':
      return Token{ch};
   case '.':
   case '0':
   case '1':
   case '2':
   case '3':
   case '4':
   case '5':
   case '6':
   case '7':
   case '8':
   case '9': {
      cin.putback(ch);
      double val;
      cin >> val;
      return Token{NUMBER, val};
   }
   default:
      if (isalpha(ch)) { // a variable must start with a letter
         string s;
         s += ch;

         // a variable must consist of only letters, digits and underscores
         while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) {
            s += ch;
         }
         cin.putback(ch);

         if (s == TERMINATION_KEY) {
            return Token{QUIT};
         }
         else if (s == DECLARATION_KEY) {
            return Token{DECLARE};
         }
         else if (s == HELP_KEY) {
            return Token{HELP};
         }
         else if (s == "sqrt") {
            return Token{SQUARE_ROOT};
         }
         else if (s == "pow") {
            return Token{POWER};
         }
         else if (s == "const") {
            return Token{CONST_VAR};
         }
         return Token{VAR_NAME, s};
      }
      throw runtime_error("Bad token");
   }
}

void TokenStream::putback(const Token& t)
{
   if (full) {
      throw runtime_error("putback() into a full buffer");
   }
   buffer = t;  // copy t to buffer
   full = true; // buffer is now full
}

void TokenStream::clean_up()
{
   full = false;

   // first look in the buffer
   if (buffer.kind == ENTER_KEY) {
      return;
   }

   // now search input:
   char ch;
   do {
      ch = static_cast<char>(cin.get());
   } while (ch != '\n');
}
