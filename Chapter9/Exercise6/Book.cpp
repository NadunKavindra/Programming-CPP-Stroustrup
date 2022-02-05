//
// Created by Mustafa on 2/2/2022.
//

#include "Book.hpp"
#include <string>
#include <stdexcept>
#include <regex>

using std::string;

bool is_valid_ISBN(const std::string& ISBN)
{
   const static std::regex ISBN_FORMAT {"^[0-9]+-[0-9]+-[0-9]+-[a-zA-Z0-9]$"};
   return std::regex_match(ISBN, ISBN_FORMAT);
}

Book::Book(const string& ISBN, const string& author, const string& title, int year)
   :ISBN{ISBN}, author{author}, title{title}, copyright_year{year}
{
   if (year <= 0 || year > 2022) {
      throw std::invalid_argument("Invalid value for year");
   }

   if (!is_valid_ISBN(ISBN)) {
      throw std::invalid_argument("Invalid ISBN. Must be of form n-n-n-x "
                                  " where n is an integer and x is digit or letter");
   }
}


std::ostream& operator<<(std::ostream& os, const Book& b)
{
   os << "Title: " << b.get_title() << '\n';
   os << "Author: " << b.get_author() << '\n';
   os << "ISBN: " << b.get_isbn();
   return os;
}