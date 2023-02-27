#ifndef REQUEST_CONTROLLER_FOR_GENERATE
#define REQUEST_CONTROLLER_FOR_GENERATE

#include "OperationForGenerate.h"
#include "Parser.h"
#include "RequestController.h"

#define SHARP_GENERATOR \
  "./C#_Api/Generator/DecimalGenerator/bin/Release/net7.0/DecimalGenerator"

#define STRING_SIZE_FOR_RANGE                            \
  (SIZE_OF_STRING_FOR_CONVERT * 3 + MAX_OPERATION_SIZE + \
   strlen(SHARP_GENERATOR))

/// @brief Creates a controller to request a C# application and collects the
/// request's string.
/// @param start The starting point of a range of numbers or the number around
/// which a range of numbers is built.
/// @param step The step between two numbers in the range.
/// @param numberOfValue Number of a value in the range.
/// @param type_of_range Type of range.
/// @return RequestController
RequestController ConstructRequestForDecimalFromRange(
    const s21_decimal* start, const s21_decimal* step, int numberOfValue,
    const char* type_of_range);

#endif
