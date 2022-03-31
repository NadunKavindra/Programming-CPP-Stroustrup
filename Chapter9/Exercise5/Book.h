#ifndef EXERCISE5_BOOK_H
#define EXERCISE5_BOOK_H

#include <string>

class Book {
public:
   Book(std::string ISBN,  std::string author, std::string title, int copyright_year);

   void check_in();
   void check_out();

   std::string get_ISBN()   const { return ISBN; }
   std::string get_title()  const { return title; }
   std::string get_author() const { return author; }

   int get_copyright_year() const { return copyright_year; }

   bool is_checked_out() const { return checked_out; }
private:
   std::string ISBN;
   std::string title;
   std::string author;
   int copyright_year;

   bool checked_out = false;
};


#endif //EXERCISE5_BOOK_H
