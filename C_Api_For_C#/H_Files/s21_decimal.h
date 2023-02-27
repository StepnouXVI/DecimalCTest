#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

#define SIGN 15
#define EXP 14

#define NEGATIVE 0b10000000

#define MAX_VALUE
#define MIN_VALUE

typedef union s21_decimal {
  uint32_t bits32[4];
  uint8_t bits8[16];

} s21_decimal;

/// @brief Adds two specified Decimal values.
/// @param value_1 The first value to add.
/// @param value_2 The second value to add.
/// @param result The sum of value_1 and value_2.
/// @return  The success of the operation.
/// @return 0 - OK.
/// @return 1 - the number is too large or equal to infinity.
/// @return 2 - the number is too small or equal to negative infinity.
/// @return 3 - division by 0.
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/// @brief Divides two specified System.Decimal values.
/// @param value_1 The dividend.
/// @param value_2 The divisor.
/// @param result The result of dividing  value_1 by value_2.
/// @return The success of the operation.
/// @return 0 - OK.
/// @return 1 - the number is too large or equal to infinity.
/// @return 2 - the number is too small or equal to negative infinity.
/// @return 3 - division by 0.
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/* conversion to float */
int s21_from_decimal_to_float(s21_decimal src, float *dst);

/* conversion to int */
int s21_from_decimal_to_int(s21_decimal src, int *dst);

/* conversion from float */
int s21_from_float_to_decimal(float src, s21_decimal *dst);

/* conversion from int */
int s21_from_int_to_decimal(int src, s21_decimal *dst);

/* comparison - the result is equal to */
int s21_is_equal(s21_decimal, s21_decimal);

/* comparison - the result is greater than or equal to */
int s21_is_greater_or_equal(s21_decimal, s21_decimal);

/* comparison - the result is more */
int s21_is_greater(s21_decimal, s21_decimal);

/* comparison - the result is less than or equal to */
int s21_is_less_or_equal(s21_decimal, s21_decimal);

/* comparison - the result is less */
int s21_is_less(s21_decimal, s21_decimal);

/* comparison - the result is not equal */
int s21_is_not_equal(s21_decimal, s21_decimal);

/// @brief Computes the remainder after dividing two Decimal values.
/// @param value_1 The dividend.
/// @param value_2 The divisor.
/// @param result The remainder after dividing value_1 by value_2.
/// @return The success of the operation.
/// @return 0 - OK.
/// @return 1 - the number is too large or equal to infinity.
/// @return 2 - the number is too small or equal to negative infinity.
/// @return 3 - division by 0.
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/// @brief Multiplies two specified Decimal values.
/// @param value_1 The multiplicand.
/// @param value_2 The multiplier.
/// @param result The result of multiplying value_1 and value_2.
/// @return The success of the operation.
/// @return 0 - OK.
/// @return 1 - the number is too large or equal to infinity.
/// @return 2 - the number is too small or equal to negative infinity.
/// @return 3 - division by 0.
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

#endif  // SRC_S21_DECIMAL_H_
