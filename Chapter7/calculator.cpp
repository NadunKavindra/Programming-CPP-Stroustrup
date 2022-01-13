/*
   Code from Chapter 7 of "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
   Code is all in one file as header files are introduced in Chapter 8

   Please note that this is NOT the final version of the calculator

   Modifications by Mustafa Adaoglu
      Exercise 2 Chapter 6: Added the option of using braces {}
      Exercise 3 Chapter 6: Added factorial operator

      Drill 7 & 8 Chapter 7: Added a square root operation
      Drill 9 Chapter 7 : Added pow() operation, e.g. pow(2.5,3) = 2.5 * 2.5 * 2.5

      Exercise 1 Chapter 7: Added the use of underscores to variable names
      Exercise 2 Chapter 7: Added assignment operator for reassigning variable values
      Exercise 3 Chapter 7: Implemented constant variables
      Exercise 4 Chapter 7: Implemented the Symbol_table class for storing variables
      Exercise 5 Chapter 7: Modified Token_stream::get() to return Token(print) when it sees a newline
      Exercise 6 Chapter 7: Added the option of printing out instructions for the user
      Exercise 7 Chapter 7: Changed the q and h commands to be quit and help respectively

      Improved error handling

      Note that, factorial operation is only defined for ints
*/

#include "../std_lib_facilities.h"

class Token {
public:
   char kind;    // what kind of token
   double value; // for numbers: a value
   string name;  // for variables: a name

   Token() : kind {0} {}
   Token(const char ch) : kind {ch} {}
   Token(const char ch, const double val) : kind {ch}, value {val} {}
   Token(const char ch, const string n) : kind {ch}, name {n} {}
};

class Token_stream {
public:
   /// The constructor just sets full to indicate that the buffer is empty:
   Token_stream() : full {false}, buffer {0} {};

   Token get();
   void putback(const Token t);
   void clean_up();       // discard characters up to and including a newline
private:
   bool full = false;
   Token buffer;      // here is where we keep a Token inserted back using putback()
};

/// Puts its argument back into the Token_stream's buffer
void Token_stream::putback(const Token t)
{
   if (full) {
      error("putback() into a full buffer");
   }
   buffer = t;  // copy t to buffer
   full = true; // buffer is now full
}

// Constants that represent the kinds of tokens
constexpr char NUMBER = '8';
constexpr char PRINT = ';';
constexpr char QUIT = 'q';
constexpr char HELP = 'h';
constexpr char DECLARE = 'D';
constexpr char CONST_VAR = 'c';
constexpr char NAME = 'a';
constexpr char SQUARE_ROOT = 's';
constexpr char POWER = 'p';

const string DECLERATION_KEY = "let";
const string HELP_KEY = "help";
const string TERMINATION_KEY = "quit";

// Read characters from cin and compose a Token
Token Token_stream::get()
{
   if (full) { // check if we already have a Token ready
      full = false;
      return buffer; // remove token from buffer
   }

   char ch;
   do {
      ch = static_cast<char>(cin.get());
      if (ch == '\n') {
         return Token{PRINT};
      }
   } while (isspace(ch));

   switch (ch) {
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
      return Token{ch}; // let each character represent itself
   case '.':             // a floating point literal can start with a dot
   case '0':
   case '1':
   case '2':
   case '3':
   case '4':
   case '5':
   case '6':
   case '7':
   case '8':
   case '9':
   {
      cin.putback(ch); // put digit back into the input stream
      double val;
      cin >> val;
      return Token{NUMBER, val};
   }
   default:
      if (isalpha(ch)) { // a variable must start with a letter
         string s;
         s += ch;

         // a variable must of conisist of only letters, digits and underscores
         while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) {
            s += ch;
         }
         cin.putback(ch);

         if (s == TERMINATION_KEY) {
            return Token{QUIT};
         }
         else if (s == DECLERATION_KEY) {
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
         return Token{NAME, s};
      }
      error("Bad token");
   }
}

/// Discard characters up to and including a newline
void Token_stream::clean_up()
{
   full = false;

   // first look in the buffer
   if (buffer.kind == PRINT) {
      return;
   }

   // now search input:
   char ch;
   do {
      ch = static_cast<char>(cin.get());
   } while (ch != '\n');
}

struct Variable {
   string name;
   double value;
   bool constant;
};

class Symbol_table {
public:
   double get_value(const string s) const;
   void set_value(const string s, const double d);
   double declare(const string var, const double val, const bool is_constant=false);
   bool is_declared(const string var) const;
private:
   vector<Variable> var_table;
};

// return the value of the Variable named s
double Symbol_table::get_value(const string s) const
{
   for (const Variable& v : var_table) {
      if (v.name == s) {
         return v.value;
      }
   }
   error("get: undefined variable ", s);
}

/// Sets the Variable named s to d
void Symbol_table::set_value(const string s, const double d)
{
   for (Variable& v : var_table) {
      if (v.name == s) {
         if (v.constant) {
            error("cannot change value of constant variable ", v.name);
         }
         v.value = d;
         return;
      }
   }
   error("set: undefined variable ", s);
}

/// Returns true if argument is already in the var table
bool Symbol_table::is_declared(const string var) const
{
   for (const Variable& v : var_table) {
      if (v.name == var) {
         return true;
      }
   }
   return false;
}

// add {var, val, is_constant} to var_table
// by default defined variables are non-constant
double Symbol_table::declare(const string var, const double val, const bool is_constant)
{
   if (is_declared(var)) {
      error(var, " declared twice");
   }
   var_table.push_back(Variable{var, val, is_constant});
   return val;
}

double expression();    // declaration so that primary() can call expression()
Token_stream ts;        // provides get() and putback()
Symbol_table variables; // used to store and keep track of variables

/// Deal with numbers and parentheses
double primary()
{
   Token t = ts.get();
   switch (t.kind) {
   case '(':
   case '{':
   {
      double d = expression();
      t = ts.get();
      if (t.kind != ')' && t.kind != '}') {
         error("')' or '}' expected");
      }
      return d;
   }
   case NUMBER:
      return t.value;
   case NAME:
      return variables.get_value(t.name);
   case '+':
      return primary();
   case '-':
      return -primary();
   default:
      error("primary expected");
   }
}

/// Does not account for potential overflow
int factorial(int n)
{
   if (n < 0) {
      error("can't perform factorial operation on a negative number");
   }

   int result = 1;
   for (int i = 2; i <= n; ++i) {
      result *= i;
   }
   return result;
}

/// Deal with pow(x,y)
double handle_pow()
{
   Token t = ts.get();
   if (t.kind != '(' && t.kind != '{') {
      error("'(' or '{' expected");
   }
   double base = expression();

   t = ts.get();
   if (t.kind != ',') {
      error("',' expected");
   }

   double exponent = expression();

   t = ts.get();
   if (t.kind != ')' && t.kind != '}') {
      error("')' or '}' expected");
   }
   return pow(base, exponent);
}

/// Deal with sqrt(x)
double handle_sqrt()
{
   Token t = ts.get();
   if (t.kind != '(') {
      error("'(' expected");
   }
   double d = expression();

   t = ts.get();
   if (t.kind != ')') {
      error("')' expected");
   }

   return sqrt(d);
}

/// Deal with math functions such as pow, sqrt...
double math_function()
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
double higher_operator()
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
double term()
{
   double left = higher_operator();
   Token t = ts.get();

   while (true) {
      switch (t.kind) {
      case '*':
         left *= higher_operator();
         t = ts.get();
         break;
      case '/':
      {
         double d = higher_operator();
         if (d == 0) {
            error("divide by zero");
         }

         left /= d;
         t = ts.get();
         break;
      }
      case '%':
      {
         double d = higher_operator();
         if (d == 0) {
            error("divide by zero");
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
double expression()
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
double decleration()
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
   if (t.kind != NAME) {
      error("name expected in decleration");
   }

   Token t2 = ts.get();
   if (t2.kind != '=') {
      error("= missing in decleration of ", t.name);
   }

   double d = expression();
   variables.declare(t.name, d, is_constant);

   // note that we returned the value stored in the new variable
   // this is useful when the initialization expression is non-trivial
   // for example: let v = y / (x2 - x1)
   return d;
}

double statement()
{
   Token t = ts.get();

   switch (t.kind) {
   case DECLARE:
      return decleration();
   case NAME:
   {
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

void print_help_info()
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
   cout << '\t' << "sqrt(x)    --> returns squre root of x\n";
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
   variables.declare("k", 1000, true);

   cout << "Welcome !!!\n";
   cout << "Enter 'help' to display support information\n";
   cout << "Enter 'quit' to quit the program\n\n";

   while (cin)
   try {
      cout << "> "; // print prompt
      Token t = ts.get();
      if (t.kind == PRINT) {
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
   catch (exception& e) {
      cerr << '\a' << "Error: " << e.what() << "\n\n";
      ts.clean_up();
   }
}

int main()
try {
   calculate();
   return 0;
}
catch (exception& e) {
   cerr << '\a' << "error: " << e.what() << '\n';
   keep_window_open("~~"); // to cope with Windows console mode
   return 1;
}
catch (...) {
   cerr << '\a' << "Oops: unknown exception!\n";
   keep_window_open("~~");
   return 2;
}
