#ifndef FUNCTION_FOR_GENERATE
#define FUNCTION_FOR_GENERATE

#include <stdio.h>

#include "OperationForGenerate.h"
#include "RequestControllerFunctionsForGenerator.h"
#include "s21_decimal.h"

/// @brief Generates a decimal number using C#.
/// @param point The starting point of the range or the point around which the
/// range is built.
/// @param step The step between two numbers in the range.
/// @param numberOfValue Number of a value in the range.
/// @param typeOfGenerator Range type: simple sequence, range around the special
/// point. Use define: "RANGE", "NEAR_POINT".
/// @return Result of generation.
s21_decimal GetDecimalFromRange(const s21_decimal* point,
                                const s21_decimal* step, int numberOfValue,
                                int typeOfGenerator);
#endif