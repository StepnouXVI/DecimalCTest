#include "../../s21_test_header.h"

static s21_decimal max_dec = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
// static s21_decimal min_dec = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
MakeHeader(s21_add) MakeHeader(s21_div) MakeHeader(s21_sub) MakeHeader(s21_mod)
    MakeHeader(s21_mul)
