#ifndef PARSER
#define PARSER

#include <stdio.h>
#include <string.h>

#include "s21_decimal.h"
#define BOOL_STRING_SIZE 10
#define BOOL_STIRNG_READ "%9s"
#define TRUE "True"
#define FALSE "False"

/// @brief Gets a decimal number from the stream.
/// @param stream
/// @return
s21_decimal GetDecimal(FILE* stream);

/// @brief Gets a float number from the stream.
/// @param stream
/// @return
float GetFloat(FILE* stream);

/// @brief Gets a int number from the stream.
/// @param stream
/// @return
int GetInt(FILE* stream);

/// @brief  Gets a bool value from the stream.
/// @param stream
/// @return 0 or 1.
int GetBool(FILE* stream);
#endif