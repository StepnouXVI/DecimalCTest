#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

#define SIGN 15
#define EXP 14

#define NEGATIVE 0b10000000



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
/// @return 1 - The number is too large or equal to infinity.               
/// @return 2 - The number is too small or equal to negative infinity.     
/// @return 3 - Division by 0.
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);


/// @brief Divides two specified Decimal values.
/// @param value_1 The dividend.
/// @param value_2 The divisor.
/// @param result The result of dividing  value_1 by value_2.
/// @return The success of the operation.
/// @return 0 - OK.                                                         
/// @return 1 - The number is too large or equal to infinity.               
/// @return 2 - The number is too small or equal to negative infinity.     
/// @return 3 - Division by 0.
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);


/// @brief Converts decimal number to float.
/// @param src 
/// @param dst Result of conversation.
/// @return Success of operation.
/// @return 0 - OK.
/// @return 1 - Some errors.
int s21_from_decimal_to_float(s21_decimal src, float *dst);

/// @brief Converts decimal number to int.
/// @param src 
/// @param dst Result of conversation.
/// @return Success of operation.
/// @return 0 - OK.
/// @return 1 - Some errors.
int s21_from_decimal_to_int(s21_decimal src, int *dst);

/// @brief Converts float number to decimal.
/// @param src 
/// @param dst Result of conversation.
/// @return Success of operation.
/// @return 0 - OK.
/// @return 1 - Some errors.
int s21_from_float_to_decimal(float src, s21_decimal *dst);

/// @brief Converts int number to decimal.
/// @param src 
/// @param dst Result of conversation.
/// @return Success of operation.
/// @return 0 - OK.
/// @return 1 - Some errors.
int s21_from_int_to_decimal(int src, s21_decimal *dst);


/// @brief Compares two decimal numbers. 
/// @param  number_1
/// @param  number_2
/// @return Returns 1 if the numbers are equal.
int s21_is_equal(s21_decimal, s21_decimal);

/// @brief Compares two decimal numbers. 
/// @param  number_1
/// @param  number_2
/// @return Returns 1 if the first number is greater than the second, or they are equal.
int s21_is_greater_or_equal(s21_decimal, s21_decimal);

/// @brief Compares two decimal numbers. 
/// @param  number_1
/// @param  number_2
/// @return Returns 1 if the first number is greater than the second, or they are equal.
int s21_is_greater(s21_decimal, s21_decimal);

/// @brief Compares two decimal numbers. 
/// @param  number_1
/// @param  number_2
/// @return Returns 1 if the first number is less than the second, or they are equal.
int s21_is_less_or_equal(s21_decimal, s21_decimal);

/// @brief Compares two decimal numbers. 
/// @param  number_1
/// @param  number_2
/// @return Returns 1 if the first number is less than the second.
int s21_is_less(s21_decimal, s21_decimal);

/// @brief Compares two decimal numbers. 
/// @param  number_1
/// @param  number_2
/// @return Returns 1 if the numbers are not equal.
int s21_is_not_equal(s21_decimal, s21_decimal);

/// @brief Computes the remainder after dividing two Decimal values.        
/// @param value_1 The dividend.
/// @param value_2 The divisor.
/// @param result The remainder after dividing value_1 by value_2.
/// @return The success of the operation.                           
/// @return 0 - OK.                                                         
/// @return 1 - The number is too large or equal to infinity.               
/// @return 2 - The number is too small or equal to negative infinity.     
/// @return 3 - Division by 0.
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/// @brief Multiplies two specified Decimal values.
/// @param value_1 The multiplicand.
/// @param value_2 The multiplier.
/// @param result The result of multiplying value_1 and value_2.
/// @return The success of the operation.
/// @return 0 - OK.                                                         
/// @return 1 - The number is too large or equal to infinity.               
/// @return 2 - The number is too small or equal to negative infinity.     
/// @return 3 - Division by 0.
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/// @brief  Subtracts one specified Decimal value from another.
/// @param value_1 The reduced.
/// @param value_2 The subtractable.
/// @param result The result of subtraction value_1 and value_2.(Difference)
/// @return The success of the operation.
/// @return 0 - OK.                                                         
/// @return 1 - The number is too large or equal to infinity.               
/// @return 2 - The number is too small or equal to negative infinity.     
/// @return 3 - Division by 0.
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/// @brief Rounds a specified Decimal number to the closest integer toward negative infinity.
/// @param value 
/// @param result Rounding result.
/// @return The success of the operation.
/// @return 0 - OK.                                                         
/// @return 1 - The number is too large or equal to infinity.               
/// @return 2 - The number is too small or equal to negative infinity.     
/// @return 3 - Division by 0.
int s21_floor(s21_decimal value, s21_decimal *result);

/// @brief Rounds a decimal value to the nearest integer.
/// @param value 
/// @param result Rounding result.
/// @return The success of the operation.
/// @return 0 - OK.                                                         
/// @return 1 - The number is too large or equal to infinity.               
/// @return 2 - The number is too small or equal to negative infinity.     
/// @return 3 - Division by 0.
int s21_round(s21_decimal value, s21_decimal *result);

/// @brief Returns the integral digits of the specified Decimal; any fractional digits are discarded, including trailing zeroes.
/// @param value 
/// @param result Rounding result.
/// @return The success of the operation.
/// @return 0 - OK.                                                         
/// @return 1 - The number is too large or equal to infinity.               
/// @return 2 - The number is too small or equal to negative infinity.     
/// @return 3 - Division by 0.
int s21_truncate(s21_decimal value, s21_decimal *result);

/// @brief Returns the result of multiplying the specified Decimal value by negative one.
/// @param value 
/// @param result The result of multiplying a number by -1.
/// @return The success of the operation.
/// @return 0 - OK.                                                         
/// @return 1 - The number is too large or equal to infinity.               
/// @return 2 - The number is too small or equal to negative infinity.     
/// @return 3 - Division by 0. 
int s21_negate(s21_decimal value, s21_decimal *result);
#endif  // SRC_S21_DECIMAL_H_
