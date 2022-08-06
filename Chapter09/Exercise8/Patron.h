#ifndef EXERCISE8_PATRON_H
#define EXERCISE8_PATRON_H

#include <string>

class Patron {
public:
   /// @param name The name of the patron
   /// @param card_number The library card number of patron
   /// @param fees The amount of fee owed by patron
   /// @throws std::invalid_argument if the value for fees is negative
   Patron(const std::string& name, int card_number, int fees);

   /// The fees owed by the patron will be set to zero.
   /// @param name The name of the patron
   /// @param card_number The library card number of patron
   Patron(const std::string& name, int card_number);

   const std::string& get_name() const { return name; }
   int get_card_number() const { return card_number; }
   int get_fees_owed() const { return fees_owed; }

   /// Adds the given amount to the total fees owed by the patron
   /// @param amount the value to be added
   /// @throws std::invalid_argument exception if the given amount is not positive
   void add_fee(int amount);

   /// Deduces the given amount from the total fees owed by the patron
   /// @param amount the value to be deduced
   /// @throws std::invalid_argument exception if the given amount is not positive
   void reduce_fee_owed(int amount);

private:
   std::string name;
   int card_number;
   int fees_owed = 0;
};

/// @returns true if and only if given patron owes a fee
inline bool owes_fees(const Patron& patron) { return patron.get_fees_owed(); }

#endif // EXERCISE8_PATRON_H
