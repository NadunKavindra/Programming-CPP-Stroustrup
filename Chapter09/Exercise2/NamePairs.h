#ifndef EXERCISE2_NAMEPAIRS_H
#define EXERCISE2_NAMEPAIRS_H


#include <vector>
#include <string>


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

   /// Prints the (name, age) pairs, one per line
   void print();

   /// Sorts the name vector in alphabetical order
   /// Reorganizes the age vector to match the sorted names
   void sort();

private:
   std::vector<std::string> names;
   std::vector<int> ages;
};


#endif //EXERCISE2_NAMEPAIRS_H
