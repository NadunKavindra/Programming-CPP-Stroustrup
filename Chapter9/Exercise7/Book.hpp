//
// Created by Mustafa on 2/2/2022.
//

#ifndef EXERCISE6_BOOK_HPP
#define EXERCISE6_BOOK_HPP

#include <ostream>
#include <string>

enum class Genre { Fiction, Nonfiction, Periodical, Biography, Children };

class Book {
public:
   Book(const std::string& ISBN, const std::string& author, const std::string& title,
        int year, Genre genre);

   std::string get_isbn() const { return ISBN; }
   Genre get_genre() const { return genre; }
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
   const Genre genre;
   bool checked_out = false;
};

std::ostream& operator<<(std::ostream& os, const Book& b);

inline bool operator==(const Book& b1, const Book& b2)
{
   return b1.get_isbn() == b2.get_isbn();
}
inline bool operator!=(const Book& b1, const Book& b2) { return !(b1 == b2); }

#endif // EXERCISE6_BOOK_HPP
