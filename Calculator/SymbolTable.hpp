/*
   Code from Chapter 7 of "Programming -- Principles and Practice Using C++"
   by Bjarne Stroustrup

   Modifications by m-adaoglu
   Please see main.cpp for more details
*/

#ifndef CALCULATOR_SYMBOLTABLE_HPP
#define CALCULATOR_SYMBOLTABLE_HPP

#include <string>
#include <vector>

struct Variable {
   std::string name;
   double value;
   bool constant;
};

class SymbolTable {
public:
   /// Sets the variable named s to value d
   void set_value(const std::string s, const double d);

   /// @returns the value of the variable named s
   double get_value(const std::string s) const;

   /// Adds {var, val, is_constant} to var_table
   /// by default defined variables are non-constant
   /// @returns the val parameter
   double declare(const std::string var, const double val,
                  const bool constant = false);

   /// @returns ture if argument is already in var table, false otherwise
   bool is_declared(const std::string var) const;
private:
   std::vector<Variable> var_table;
};

#endif // CALCULATOR_SYMBOLTABLE_HPP
