#include <stdio.h>
#include <stdlib.h>

#ifndef CONVERTER_TO_STRING
#define CONVERTER_TO_STRING

#include "s21_decimal.h"

#define SIZE_OF_STRING_FOR_CONVERT 50
#define PARAMS_FOR_DECIMAL_OUTPUT(number)                              \
  "%u %u %u %u", number.bits32[0], number.bits32[1], number.bits32[2], \
      number.bits32[3]

/// @brief Converts a decimal number to a string of four ints.
/// @attention Using malloc.
/// @param number
/// @return String of four ints.
char *ConvertDecimal(const s21_decimal *number);

/// @brief  Converts a int number to a string of four ints.
/// @attention Using malloc.
/// @param number
/// @return Stirng.
char *ConvertInt(int *number);

/// @brief  Converts a decimal flat to a string of four ints.
/// @attention Using malloc.
/// @param number
/// @return String.
char *ConvertFloat(float *number);

#endif