/*
   Code from Chapter 7 of "Programming -- Principles and Practice Using C++"
   by Bjarne Stroustrup

   Modifications by m-adaoglu
   Exercise 2 Chapter 6: Added the option of using braces {}
   Exercise 3 Chapter 6: Added factorial operator

   Drill 7 & 8 Chapter 7: Added a square root operation
   Drill 9 Chapter 7    : Added pow() operation, e.g. pow(2.5,3) = 2.5 * 2.5 * 2.5

   Exercise 1 Chapter 7: Added the use of underscores to variable names
   Exercise 2 Chapter 7: Added assignment operator for reassigning variable values
   Exercise 3 Chapter 7: Implemented constant variables
   Exercise 4 Chapter 7: Implemented the Symbol_table class for storing variable
   Exercise 5 Chapter 7: Modified Token_stream::get() to return Token(print)
                         when it sees a newline
   Exercise 6 Chapter 7: Added the option of printing out instructions for the
   user

   Exercise 7 Chapter 7: Changed the q and h commands to quit and help
   respectively

   Improved error handling
   Arranged into headers and source files
*/

#pragma once

#include "SymbolTable.h"
#include "TokenStream.h"
#include <iosfwd>

class Calculator {
public:
   /// @param is input stream to be read from
   /// @param os output stream to be written to
   Calculator(std::istream& is, std::ostream& os);

   /// @brief Reads a mathematical statement from input
   /// and writes the answer to output. (I/O streams specified in constructor)
   void calculate();

private:
   std::istream& input;
   std::ostream& output;

   TokenStream ts;
   SymbolTable variables;

   double primary();
   double handle_pow();
   double math_function();
   double higher_operator();
   double term();
   double expression();
   double declaration();
   double statement();

   double factorial(int n);
};
