/*
   Code from Chapter 7 of "Programming -- Principles and Practice Using C++"
   by Bjarne Stroustrup

   Modifications by m-adaoglu
   Please see Calculator.h for more details
*/

#include "TokenStream.h"
#include "Token.h"
#include <istream>
#include <stdexcept>
#include <string>

using std::runtime_error;
using std::string;

Token TokenStream::get()
{
   if (full) { // check if we already have a Token ready
      full = false;
      return buffer; // remove token from buffer
   }

   char ch = 0;
   do {
      ch = static_cast<char>(input_stream.get());
      if (ch == EOF) {
         return Token {EMPTY_STRING};
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
      return Token {ch};
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
      input_stream.putback(ch);
      double val;
      input_stream >> val;
      return Token {NUMBER, val};
   }
   default:
      if (isalpha(ch)) { // a variable must start with a letter
         string s;
         s += ch;

         // a variable must consist of only letters, digits and underscores
         while (input_stream.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) {
            s += ch;
         }
         input_stream.putback(ch);

         if (s == TERMINATION_KEY) {
            return Token {QUIT};
         }
         else if (s == DECLARATION_KEY) {
            return Token {DECLARE};
         }
         else if (s == HELP_KEY) {
            return Token {HELP};
         }
         else if (s == "sqrt") {
            return Token {SQUARE_ROOT};
         }
         else if (s == "pow") {
            return Token {POWER};
         }
         else if (s == "const") {
            return Token {CONST_VAR};
         }
         return Token {VAR_NAME, s};
      }
      throw runtime_error("Bad token/operation");
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
   if (buffer.kind == EMPTY_STRING) {
      buffer = 0;
      return;
   }

   // now search input:
   char ch = 0;
   do {
      ch = static_cast<char>(input_stream.get());
   } while (ch != EOF);
   input_stream.clear(std::ios_base::failbit);
}
