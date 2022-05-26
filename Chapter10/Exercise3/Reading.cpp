#include "Reading.h"
#include <stdexcept>
#include <ostream>

Reading::Reading(int hour, double temperature) :hour{hour}, temperature{temperature}
{
   // Constants defined in the book
   static constexpr int max = 200;
   static constexpr int min = -200;

   if (hour > 23 || hour < 0) {
      throw std::invalid_argument("An hour value must be between 0 and 23 (inclusive)");
   }

   if (temperature < min || temperature > max) {
      throw std::invalid_argument("Temperature value is invalid");
   }
}
std::ostream& operator<<(std::ostream& os, const Reading& r)
{
   return os << r.hour << ' ' << r.temperature;
}
