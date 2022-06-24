#include "Calculator.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

Calculator::Calculator(std::istream& is, std::ostream& os)
    : input {is},
      output {os},
      ts {is}
{
   // predefine some constant names:
   variables.declare("pi", 3.1415926535, true);
   variables.declare("e", 2.7182818284, true);
}

void Calculator::calculate()
{
   while (input)
      try {
         Token t = ts.get();
         if (t.kind == EMPTY_STRING) {
            return;
         }
         ts.putback(t);
         output << statement();
         ts.clean_up();
      }
      catch (const std::exception& e) {
         output << "Error: " << e.what();
         ts.clean_up();
         return;
      }
}

/// Deal with numbers and parentheses
double Calculator::primary()
{
   Token t = ts.get();
   switch (t.kind) {
   case '(':
   case '{': {
      const double d = expression();
      t = ts.get();
      if (t.kind != ')' && t.kind != '}') {
         throw std::runtime_error("')' or '}' expected");
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
      throw std::runtime_error("primary expected");
   }
}

/// Deal with pow(x,y)
double Calculator::handle_pow()
{
   Token t = ts.get();
   if (t.kind != '(' && t.kind != '{') {
      throw std::runtime_error("'(' or '{' expected");
   }
   const double base = expression();

   t = ts.get();
   if (t.kind != ',') {
      throw std::runtime_error("',' expected");
   }

   const double exponent = expression();

   t = ts.get();
   if (t.kind != ')' && t.kind != '}') {
      throw std::runtime_error("')' or '}' expected");
   }
   return pow(base, exponent);
}

/// Deal with math functions such as pow, sqrt...
double Calculator::math_function()
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
double Calculator::higher_operator()
{
   const double left = math_function();
   Token t = ts.get();

   while (true) {
      switch (t.kind) {
      case '!':
         return factorial(static_cast<int>(left));
      default:
         ts.putback(t);
         return left;
      }
   }
}

/// Deal with *, / and %
double Calculator::term()
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
         const double d = higher_operator();
         if (d == 0) {
            throw std::runtime_error("divide by zero");
         }

         left /= d;
         t = ts.get();
         break;
      }
      case '%': {
         const double d = higher_operator();
         if (d == 0) {
            throw std::runtime_error("divide by zero");
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
double Calculator::expression()
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
         return left; // finally: no more + or - : return the answer
      }
   }
}

/// Handles name = expression and const name = expression
double Calculator::declaration()
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
      throw std::runtime_error("name expected in declaration");
   }

   Token t2 = ts.get();
   if (t2.kind != '=') {
      throw std::runtime_error("= missing in declaration of " + t.name);
   }

   const double d = expression();
   variables.declare(t.name, d, is_constant);

   // note that we returned the value stored in the new variable
   // this is useful when the initialization expression is non-trivial
   // for example: let v = y / (x2 - x1)
   return d;
}

double Calculator::statement()
{
   Token t = ts.get();

   switch (t.kind) {
   case DECLARE:
      return declaration();
   case VAR_NAME: {
      Token t2 = ts.get();

      if (t2.kind == '=') {
         const double d = expression();
         variables.set_value(t.name, d);
         return d;
      }
      input.unget();
   }
   default:
      ts.putback(t);
      return expression();
   }
}

double Calculator::factorial(int n)
{
   if (n < 0) {
      throw std::runtime_error("factorial on negative number");
   }
   double result = 1;
   while (n > 1) {
      result *= n;
      --n;
   }
   return result;
}
