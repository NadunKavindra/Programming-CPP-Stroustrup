/*
   Exercise 5 on Page 339:
   This exercise and the next few involve the design and implementation of a book class
*/

#include "../../std_lib_facilities.h"

class Book {
public:
   Book(string ISBN, string title, string author, unsigned int year);
   void checkIn() { on_loan = false; }
   void checkOut() { on_loan = true; }

   string get_ISBN() const { return ISBN; }
   string get_title() const { return title; }
   string get_author() const { return author; }
   bool get_loan_status() const { return on_loan; }
   unsigned int get_year() const { return copyright_year; }
private:
   bool on_loan { false };
   const string ISBN;
   const string title;
   const string author;
   const unsigned int copyright_year;
};

// Returns true if the ISBN is of the format n-n-n-x
// Where n is an integer and x is a digit or a leter
bool is_valid_ISBN(const string ISBN)
{
   const regex ISBN_format { "^[0-9]+-[0-9]+-[0-9]+-[a-zA-Z0-9]$" };
   return regex_match(ISBN, ISBN_format);
}

Book::Book(string ISBN, string title, string author, unsigned int year)
   :ISBN{ISBN}, title{title}, author{author}, copyright_year{year}
{
   if (!is_valid_ISBN(ISBN)) {
      error("Invalid ISBN");
   }
}
