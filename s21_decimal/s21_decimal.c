#include "../libs/s21_decimal.h"

#include "../C_Api_For_C#_libs/C#_Api_Test.h"
#include "../C_Api_For_C#_libs/Operations.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  return get_result_operation_binary(&value_1, &value_2, result, SUM_OP);
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  return get_result_operation_binary(&value_1, &value_2, result, DIV_OP);
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  return get_value_s21_decimal_float(&src, dst);
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  return get_value_s21_decimal_int(&src, dst);
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  return get_value_float_s21_decimal(&src, dst);
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  return get_value_int_s21_decimal(&src, dst);
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  get_result_operation_comparator(&value_1, &value_2, &result, EQUAL_OP);
  return result;
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;

  get_result_operation_comparator(&value_1, &value_2, &result,
                                  MORE_OR_EQUAL_OP);
  return result;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  get_result_operation_comparator(&value_1, &value_2, &result, MORE_OP);
  return result;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;

  return get_result_operation_comparator(&value_1, &value_2, &result,
                                         LESS_OR_EQUAL_OP);
  return result;
}

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;

  return get_result_operation_comparator(&value_1, &value_2, &result, LESS_OP);
  return result;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;

  return get_result_operation_comparator(&value_1, &value_2, &result,
                                         NOT_EQUAL_OP);
  return result;
}

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  return get_result_operation_binary(&value_1, &value_2, result, REMAINDER_OP);
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  return get_result_operation_binary(&value_1, &value_2, result, MUL_OP);
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  return get_result_operation_binary(&value_1, &value_2, result, SUB_OP);
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  return get_result_operation_unary(&value, result, FLOOR_OP);
}

int s21_round(s21_decimal value, s21_decimal *result) {
  return get_result_operation_unary(&value, result, ROUND_OP);
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  return get_result_operation_unary(&value, result, TRUNCATE_OP);
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  return get_result_operation_unary(&value, result, NEGATIVE_OP);
}