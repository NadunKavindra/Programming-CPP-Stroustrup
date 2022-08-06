#ifndef EXERCISE2_NAMEPAIRS_H
#define EXERCISE2_NAMEPAIRS_H


#include <vector>
#include <string>
#include <iosfwd>

class NamePairs {
public:

   /// Prompts user to enter names
   /// Reads the name from cin
   /// Adds the name to the object's names vector
   void read_names();

   /// Prompts the user to enter an age for each name
   /// Adds the age to the object's ages vector
   /// @throws std::runtime_error if the age value is not a positive int
   void read_ages();

   /// Sorts the name vector in alphabetical order
   /// Reorganizes the age vector to match the sorted names
   void sort();

   const std::vector<std::string>& get_names() const { return names; }
   const std::vector<int>& get_ages() const { return ages; }
private:
   std::vector<std::string> names;
   std::vector<int> ages;
};


/// Prints out the (name, age) pairs (one per line)
std::ostream& operator<<(std::ostream& os, const NamePairs& np);


/// Exercise description does not define the == operator
/// Currently relies on the definition of the == operator for vectors
inline bool operator==(const NamePairs& np1, const NamePairs& np2) {
   return (np1.get_names() == np2.get_names()) && (np1.get_ages() == np2.get_ages());
}

inline bool operator!=(const NamePairs& np1, const NamePairs& np2) {
   return !(np1 == np2);
}

#endif //EXERCISE2_NAMEPAIRS_H
