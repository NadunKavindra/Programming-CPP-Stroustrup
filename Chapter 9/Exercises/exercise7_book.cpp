/*
   Exercise 6 on Page 340:
   Added a Genre enum and a Genre data member to the Book class from Exercise 5.
*/

#include "../../std_lib_facilities.h"

const enum class Genre {fiction, nonfiction, periodical, biography, children};

class Book {
public:  
   Book(string ISBN, string title, string author, unsigned int year, Genre genre);
   void checkIn() { on_loan = false; }
   void checkOut() { on_loan = true; }

   string get_ISBN() const { return ISBN; }
   string get_title() const { return title; }
   string get_author() const { return author; }
   Genre get_genre() const { return genre; }
   bool get_loan_status() const { return on_loan; }
   unsigned int get_year() const { return copyright_year; }
private:
   bool on_loan { false };
   const string ISBN;
   const string title;
   const string author;
   const Genre genre;
   const unsigned int copyright_year;
};

// Returns true if the ISBN is of the format n-n-n-x
// Where n is an integer and x is a digit or a leter
bool is_valid_ISBN(const string ISBN)
{
   const regex ISBN_format { "^[0-9]+-[0-9]+-[0-9]+-[a-zA-Z0-9]$" };
   return regex_match(ISBN, ISBN_format);
}

Book::Book(string ISBN, string title, string author, unsigned int year, Genre genre)
   :ISBN{ISBN}, title{title}, author{author}, copyright_year{year}, genre{genre}
{
   if (!is_valid_ISBN(ISBN)) {
      error("Invalid ISBN: ", ISBN);
   }
}

bool operator==(const Book& b1, const Book& b2)
{
   return b1.get_ISBN() == b2.get_ISBN();
}

bool operator!=(const Book& b1, const Book& b2)
{
   return !(b1 == b2);
}

ostream& operator<<(ostream& os, const Book& b)
{
   return os << "Title: " << b.get_title() << '\n'
             << "Author: " << b.get_author() << '\n'
             << "ISBN: " << b.get_ISBN();
}

int main()
try {
   Book test1 {"456-4563-212-C", "TESTING", "Mustafa Adaoglu", 2021, Genre::nonfiction};
   Book test2 {"457-6548-2236-D", "FURTHER TESTING", "Mustafa Adaoglu", 2021, Genre::fiction};

   cout << test1 << "\n\n";
   cout << test2 << "\n\n";

   if (test1 != test2) {
      cout << "They are different books\n";
   }
}
catch(exception& e) {
   cerr << "Error: " << e.what() << '\n';
}
catch (...) {
   cerr << "Error: unknown exception\n";
}
