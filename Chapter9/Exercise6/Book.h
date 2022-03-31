#ifndef EXERCISE5_BOOK_H
#define EXERCISE5_BOOK_H

#include <iosfwd>
#include <string>

class Book {
public:
   Book(const std::string& ISBN, const std::string& author, const std::string& title,
        int copyright_year);

   void check_in();
   void check_out();

   std::string get_ISBN() const { return ISBN; }
   std::string get_title() const { return title; }
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

inline bool operator==(const Book& b1, const Book& b2)
{
   return b1.get_ISBN() == b2.get_ISBN();
}

inline bool operator!=(const Book& b1, const Book& b2) { return !(b1 == b2); }

/// Prints the author, title and ISBN, on seperate lines
std::ostream& operator<<(std::ostream& os, const Book& b);

#endif // EXERCISE5_BOOK_H
