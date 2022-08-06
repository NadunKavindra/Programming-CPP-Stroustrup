//
// Created by Mustafa on 3/31/2022.
//

#include "Book.h"
#include <regex>
#include <stdexcept>
#include <string>

using std::string;

Book::Book(const string& ISBN, const string& author, const string& title,
           const int copyright_year)
    : ISBN{ISBN}, author{author}, title{title}, copyright_year{copyright_year}
{
   const static std::regex ISBN_PATTERN{"^[0-9]+-[0-9]+-[0-9]+-[a-zA-Z0-9]$"};

   if (!std::regex_match(ISBN, ISBN_PATTERN)) {
      throw std::invalid_argument("Invalid ISBN format");
   }

   // Would be better to get current year dynamically
   if (copyright_year < 1 || copyright_year > 2022) {
      throw std::invalid_argument("Invalid Copyright Year");
   }
}

void Book::check_in()
{
   if (!checked_out) {
      throw std::runtime_error("Book is already checked in");
   }
   checked_out = false;
}

void Book::check_out()
{
   if (checked_out) {
      throw std::runtime_error("Book is already checked out");
   }
   checked_out = true;
}
