#ifndef REQUEST_CONTROLLER_FOR_TEST
#define REQUEST_CONTROLLER_FOR_TEST

#include "RequestController.h"

#define SHARP_TESTER \
  "./C#_Api/Tester/DecimalOperationsTester/bin/Release/net7.0/Decimal"

#define MAX_SIZE_OF_OPERATION 10
#define STRING_SIZE_FOR_BINARY                              \
  (SIZE_OF_STRING_FOR_CONVERT * 2 + MAX_SIZE_OF_OPERATION + \
   strlen(SHARP_TESTER))
#define STRING_SIZE_FOR_UNARY \
  (SIZE_OF_STRING_FOR_CONVERT + MAX_SIZE_OF_OPERATION + strlen(SHARP_TESTER))

/// @brief Creates a controller to request a C# application and collects the
/// request's string.
/// @param num1 First number. (Decimal)
/// @param num2 Second number. (Decimal)
/// @param typeOfOperation The type of operation that C# will perform.
/// @return Request controller.
RequestController ConstructRequestBinary(const s21_decimal* num1,
                                         const s21_decimal* num2,
                                         const char* typeOfOperation);

/// @brief Creates a controller to request a C# application and collects the
/// request's  string.
/// @param num Number.(Decimal)
/// @param typeOfOperation The type of operation that C# will perform.
/// @return Request controller.
RequestController ConstructRequestUnary(const s21_decimal* num,
                                        const char* typeOfOperation);

/// @brief Creates a controller to request a C# application and collects the
/// request's  string.
/// @param num Number.(Float)
/// @param typeOfOperation The type of operation that C# will perform.
/// @return Request controller.
RequestController ConstructRequestConvertFloat(float* num,
                                               const char* typeOfOperation);

/// @brief Creates a controller to request a C# application and collects the
/// request's  string.
/// @param num Number.(int)
/// @param typeOfOperation The type of operation that C# will perform.
/// @return Request controller.
RequestController ConstructRequestConvertInt(int* num,
                                             const char* typeOfOperation);
#endif