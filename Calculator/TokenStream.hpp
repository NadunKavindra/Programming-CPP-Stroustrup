/*
   Code from Chapter 7 of "Programming -- Principles and Practice Using C++"
   by Bjarne Stroustrup

   Modifications by m-adaoglu
   Please see main.cpp for more details
*/

#ifndef CALCULATOR_TOKENSTREAM_HPP
#define CALCULATOR_TOKENSTREAM_HPP

#include "Token.hpp"

class TokenStream {
public:
   TokenStream() : full{false}, buffer{0} {};

   /// Read characters from cin and compose a Token
   Token get();

   /// Puts its argument back into the TokenStream's buffer
   void putback(const Token& t);

   /// Discard characters upto and including a newline
   void clean_up();
private:
   bool full;
   Token buffer;
};

#endif // CALCULATOR_TOKENSTREAM_HPP
