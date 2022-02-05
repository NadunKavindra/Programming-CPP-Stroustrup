//
// Created by Mustafa on 2/2/2022.
//

#ifndef EXERCISE5_BOOK_HPP
#define EXERCISE5_BOOK_HPP

#include <string>

class Book {
public:
   Book(const std::string& ISBN, const std::string& author, const std::string& title,
        int year);

   std::string get_isbn() const { return ISBN; }
   std::string get_author() const { return author; }
   std::string get_title() const { return title; }
   int get_copyright_year() const { return copyright_year; }
   bool is_checked_out() const { return checked_out; }


   void checkin() { checked_out = false; }
   void checkout() { checked_out = true; }
private:
   const std::string ISBN;
   const std::string author;
   const std::string title;
   const int copyright_year;
   bool checked_out = false;
};

#endif // EXERCISE5_BOOK_HPP
