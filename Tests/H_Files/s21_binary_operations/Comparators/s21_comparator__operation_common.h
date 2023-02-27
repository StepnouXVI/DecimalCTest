#include "../../s21_test_header.h"
static s21_decimal max_dec = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
// static s21_decimal min_dec = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};

MakeHeader(s21_is_equal) MakeHeader(s21_is_not_equal)
    MakeHeader(s21_is_less_or_equal) MakeHeader(s21_is_less)
        MakeHeader(s21_is_greater) MakeHeader(s21_is_greater_or_equal)
