/*
    Code from Chapter 7 of "Programming -- Principles and Practice Using C++"
    by Bjarne Stroustrup

   Modifications by m-adaoglu
   Please see main.cpp for more details
*/

#ifndef CALCULATOR_TOKEN_HPP
#define CALCULATOR_TOKEN_HPP

#include <string>

// Constants that represent the kinds of tokens
constexpr char NUMBER = '8';
constexpr char ENTER_KEY = 'e';
constexpr char QUIT = 'q';
constexpr char HELP = 'h';
constexpr char DECLARE = 'D';
constexpr char CONST_VAR = 'c';
constexpr char VAR_NAME = 'a';
constexpr char SQUARE_ROOT = 's';
constexpr char POWER = 'p';
const std::string DECLARATION_KEY = "let";
const std::string HELP_KEY = "help";
const std::string TERMINATION_KEY = "quit";

class Token {
public:
   char kind;
   double value = 0;   /// For numbers: a value
   std::string name;   /// For variables: a name

   Token() : kind{0} {}
   Token(const char ch) : kind{ch} {}
   Token(const char ch, const double val) : kind{ch}, value{val} {}
   Token(const char ch, const std::string n) : kind{ch}, name{n} {}
};

#endif // CALCULATOR_TOKEN_HPP
