#ifndef EXERCISE2_READING_H
#define EXERCISE2_READING_H

#include <iosfwd>

struct Reading {
   int hour;           // 0:23
   double temperature; // in Fahrenheit
   Reading(int hour, double temperature);
};

std::ostream& operator<<(std::ostream& os, const Reading& r);

#endif // EXERCISE2_READING_H
