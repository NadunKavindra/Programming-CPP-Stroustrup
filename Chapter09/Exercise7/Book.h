#ifndef EXERCISE7_BOOK_H
#define EXERCISE7_BOOK_H

#include <iosfwd>
#include <string>

enum class Genre { FICTION, NONFICTION, PERIODICAL, BIOGRAPHY, CHILDREN };

class Book {
public:
   Book(const std::string& ISBN, const std::string& author, const std::string& title,
        int copyright_year, Genre genre);

   void check_in();
   void check_out();

   std::string get_ISBN() const { return ISBN; }
   std::string get_title() const { return title; }
   std::string get_author() const { return author; }
   Genre get_genre() const { return genre; }

   int get_copyright_year() const { return copyright_year; }

   bool is_checked_out() const { return checked_out; }

private:
   std::string ISBN;
   std::string title;
   std::string author;
   int copyright_year;
   Genre genre;
   bool checked_out = false;
};

inline bool operator==(const Book& b1, const Book& b2)
{
   return b1.get_ISBN() == b2.get_ISBN();
}

inline bool operator!=(const Book& b1, const Book& b2) { return !(b1 == b2); }

/// Prints the author, title and ISBN, on separate lines
std::ostream& operator<<(std::ostream& os, const Book& b);

#endif // EXERCISE7_BOOK_H
