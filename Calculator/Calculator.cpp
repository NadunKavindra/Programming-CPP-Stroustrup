/*
   Code from Chapter 7 of "Programming -- Principles and Practice Using C++"
   by Bjarne Stroustrup

   Modifications by m-adaoglu
   Please see main.cpp for more details
*/

#include "Calculator.hpp"
#include "SymbolTable.hpp"
#include "Token.hpp"
#include "TokenStream.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

static TokenStream ts;        // provides get() and putback()
static SymbolTable variables; // used to store and keep track of variables
static double expression();   // declaration so that primary() can call expression()

/// Deal with numbers and parentheses
static double primary()
{
   Token t = ts.get();
   switch (t.kind) {
   case '(':
   case '{': {
      double d = expression();
      t = ts.get();
      if (t.kind != ')' && t.kind != '}') {
         throw runtime_error("')' or '}' expected");
      }
      return d;
   }
   case NUMBER:
      return t.value;
   case VAR_NAME:
      return variables.get_value(t.name);
   case '+':
      return primary();
   case '-':
      return -primary();
   default:
      throw runtime_error("primary expected");
   }
}

/// Does not account for potential overflow
static int factorial(int n)
{
   if (n < 0) {
      throw runtime_error("can't perform factorial operation on a negative number");
   }

   int result = 1;
   for (int i = 2; i <= n; ++i) {
      result *= i;
   }
   return result;
}

/// Deal with pow(x,y)
static double handle_pow()
{
   Token t = ts.get();
   if (t.kind != '(' && t.kind != '{') {
      throw runtime_error("'(' or '{' expected");
   }
   double base = expression();

   t = ts.get();
   if (t.kind != ',') {
      throw runtime_error("',' expected");
   }

   double exponent = expression();

   t = ts.get();
   if (t.kind != ')' && t.kind != '}') {
      throw runtime_error("')' or '}' expected");
   }
   return pow(base, exponent);
}

/// Deal with math functions such as pow, sqrt...
static double math_function()
{
   Token t = ts.get();
   while (true) {
      switch (t.kind) {
      case SQUARE_ROOT:
         return sqrt(primary());
      case POWER:
         return handle_pow();
      default:
         ts.putback(t);
         return primary();
      }
   }
}

/// Deal with !
static double higher_operator()
{
   double left = math_function();
   Token t = ts.get();

   while (true) {
      switch (t.kind) {
      case '!':
         return factorial(static_cast<int>(left)); // Factorial is defined for ints
      default:
         ts.putback(t);
         return left;
      }
   }
}

/// Deal with *, / and %
static double term()
{
   double left = higher_operator();
   Token t = ts.get();

   while (true) {
      switch (t.kind) {
      case '*':
         left *= higher_operator();
         t = ts.get();
         break;
      case '/': {
         double d = higher_operator();
         if (d == 0) {
            throw runtime_error("divide by zero");
         }

         left /= d;
         t = ts.get();
         break;
      }
      case '%': {
         double d = higher_operator();
         if (d == 0) {
            throw runtime_error("divide by zero");
         }

         left = fmod(left, d);
         t = ts.get();
         break;
      }
      default:
         ts.putback(t);
         return left;
      }
   }
}

/// Deal with + and -
static double expression()
{
   double left = term();
   Token t = ts.get();

   while (true) {
      switch (t.kind) {
      case '+':
         left += term();
         t = ts.get();
         break;
      case '-':
         left -= term();
         t = ts.get();
         break;
      default:
         ts.putback(t);
         return left; // finally: no more + or -: return the answer
      }
   }
}

/// Handles name = expression and const name = expression
static double declaration()
{
   bool is_constant = false;

   Token t = ts.get();
   if (t.kind == CONST_VAR) {
      is_constant = true;
   }
   else {
      ts.putback(t);
   }

   t = ts.get();
   if (t.kind != VAR_NAME) {
      throw runtime_error("name expected in declaration");
   }

   Token t2 = ts.get();
   if (t2.kind != '=') {
      throw runtime_error("= missing in declaration of " + t.name);
   }

   double d = expression();
   variables.declare(t.name, d, is_constant);

   // note that we returned the value stored in the new variable
   // this is useful when the initialization expression is non-trivial
   // for example: let v = y / (x2 - x1)
   return d;
}

static double statement()
{
   Token t = ts.get();

   switch (t.kind) {
   case DECLARE:
      return declaration();
   case VAR_NAME: {
      Token t2 = ts.get();

      if (t2.kind == '=') {
         double d = expression();
         variables.set_value(t.name, d);
         return d;
      }
      cin.unget();
   }
   default:
      ts.putback(t);
      return expression();
   }
}

static void print_help_info()
{
   cout << "The following operations are supported:\n";
   cout << '\t' << "x + y" << '\n';
   cout << '\t' << "x - y" << '\n';
   cout << '\t' << "x * y" << '\n';
   cout << '\t' << "x / y" << '\n';
   cout << '\t' << "x % y" << '\n';
   cout << '\t'
        << "x!         --> returns the factorial of (int) x (e.g. 2.5! is "
           "considered as 2!)\n";
   cout << '\t' << "sqrt(x)    --> returns square root of x\n";
   cout << '\t' << "pow(x, y)  --> returns x to the power of y\n\n";

   cout << "You can declare variables using the notation 'let variable_name = "
           "expression'\n";
   cout << "You can declare constant variables using the notation 'let const "
           "variable_name = expression'\n";
   cout << "You can assign a different value to a non constant variable using the "
           "notation 'var_name = expression'\n";
   cout << "A variable name can only contain digits, letters and underscores\n\n";
}

void calculate()
{
   // predefine some constant names:
   variables.declare("pi", 3.1415926535, true);
   variables.declare("e", 2.7182818284, true);

   cout << "Welcome !!!\n";
   cout << "Enter 'help' to display support information\n";
   cout << "Enter 'quit' to quit the program\n\n";

   while (cin)
   try {
      cout << "> "; // print prompt
      Token t = ts.get();

      if (t.kind == ENTER_KEY) {
         t = ts.get();
      }

      if (t.kind == QUIT) {
         return;
      }

      if (t.kind == HELP) {
         print_help_info();
         continue;
      }
      ts.putback(t);
      cout << "= " << statement() << "\n\n";
   }
   catch (const exception& e) {
      cerr << '\a' << "Error: " << e.what() << "\n\n";
      ts.clean_up();
   }
}
