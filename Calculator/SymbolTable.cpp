/*
   Code from Chapter 7 of "Programming -- Principles and Practice Using C++"
   by Bjarne Stroustrup

   Modifications by m-adaoglu
   Please see main.cpp for more details
*/

#include "SymbolTable.hpp"
#include <stdexcept>
#include <string>

using std::invalid_argument;
using std::runtime_error;
using std::string;

double SymbolTable::get_value(const string s) const
{
   for (const Variable& v : var_table) {
      if (v.name == s) {
         return v.value;
      }
   }
   throw runtime_error("get: undefined variable " + s);
}

void SymbolTable::set_value(const string s, const double d)
{
   for (Variable& v : var_table) {
      if (v.name == s) {
         if (v.constant) {
            throw runtime_error("cannot change value of constant variable "
                                + v.name);
         }
         v.value = d;
         return;
      }
   }
   throw runtime_error("set: undefined variable " + s);
}

double SymbolTable::declare(const string var, const double val, const bool constant)
{
   if (is_declared(var)) {
      throw invalid_argument(var + " declared twice");
   }
   var_table.push_back(Variable{var, val, constant});
   return val;
}

bool SymbolTable::is_declared(const string var) const
{
   for (const Variable& v : var_table) {
      if (v.name == var) {
         return true;
      }
   }
   return false;
}
