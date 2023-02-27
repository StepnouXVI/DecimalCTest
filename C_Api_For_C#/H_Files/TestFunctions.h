#ifndef FUNCTION_FOR_TESTING
#define FUNCTION_FOR_TESTING

#include "Operations.h"
#include "s21_decimal.h"

/// @brief Returns the result of a С# application calculation.
/// @param num_1
/// @param num_2
/// @param result
/// @param type_of_operation
/// @return The success of the operation.
/// @return 0 - OK.
/// @return 1 - the number is too large or equal to infinity.
/// @return 2 - the number is too small or equal to negative infinity.
/// @return 3 - division by 0.
int get_result_operation_binary(const s21_decimal *num_1,
                                const s21_decimal *num_2, s21_decimal *result,
                                const char *type_of_operation);

/// @brief Returns the result of a С# application calculation.
/// @param num
/// @param result
/// @param type_of_operation
/// @return The success of the operation.
/// @return 0 - OK.
/// @return 1 - the number is too large or equal to infinity.
/// @return 2 - the number is too small or equal to negative infinity.
/// @return 3 - division by 0.
int get_result_operation_unary(const s21_decimal *num, s21_decimal *result,
                               const char *type_of_operation);

/// @brief Returns the result of a С# application calculation.
/// @param num_1
/// @param num_2
/// @param result The boolean value obtained from the comparison.
/// @param type_of_operation
/// @return The success of the operation.
/// @return 0 - OK.
/// @return 1 - the number is too large or equal to infinity.
/// @return 2 - the number is too small or equal to negative infinity.
/// @return 3 - division by 0.
int get_result_operation_comparator(const s21_decimal *num_1,
                                    const s21_decimal *num_2, int *result,
                                    const char *type_of_operation);

/// @brief Returns the result of converting a number to a decimal. (Using C#)
/// @param num Value for converting.
/// @param result Result of converting.
/// @return The success of the operation.
/// @return 0 - OK.
/// @return 1 -Some errors.
int get_value_int_s21_decimal(int *num, s21_decimal *result);

/// @brief Returns the result of converting a number to a decimal. (Using C#)
/// @param num Value for converting.
/// @param result Result of converting.
/// @return The success of the operation.
/// @return 0 - OK.
/// @return 1 -Some errors.
int get_value_float_s21_decimal(float *num, s21_decimal *result);

/// @brief Returns the result of converting a number to a int. (Using C#)
/// @param num Value for converting.
/// @param result Result of converting.
/// @return The success of the operation.
/// @return 0 - OK.
/// @return 1 -Some errors.
int get_value_s21_decimal_float(const s21_decimal *num, float *result);

/// @brief Returns the result of converting a number to a int. (Using C#)
/// @param num Value for converting.
/// @param result Result of converting.
/// @return The success of the operation.
/// @return 0 - OK.
/// @return 1 -Some errors.
int get_value_s21_decimal_int(const s21_decimal *num, int *result);

#endif