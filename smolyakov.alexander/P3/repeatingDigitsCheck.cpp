#include "repeatingDigitsCheck.hpp"
#include <cctype>

int containsRepeatingDigits(const char* string, std::size_t length)
{
  int digitsCount[10] = {0};

  for (size_t i = 0; i < length; i++)
  {
    if (std::isdigit(string[i]))
    {
      int digit = string[i] - '0';
      if (digitsCount[digit]++ > 0)
      {
        return 1;
      }
    }
  }
  return 0;
}
