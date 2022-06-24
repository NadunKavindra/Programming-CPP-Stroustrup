/*
   Code from Chapter 7 of "Programming -- Principles and Practice Using C++"
   by Bjarne Stroustrup

   Modifications by m-adaoglu
   Please see Calculator.h for more details
*/

#pragma once

#include "Token.h"
#include <iosfwd>

class TokenStream {
public:
   TokenStream(std::istream& is) : input_stream {is}, full {false}, buffer {0} {};

   /// Read characters from input stream and compose a Token
   Token get();

   /// Puts its argument back into the TokenStream's buffer
   void putback(const Token& t);

   /// Discard characters upto and including a newline
   void clean_up();

private:
   std::istream& input_stream;
   bool full;
   Token buffer;
};
