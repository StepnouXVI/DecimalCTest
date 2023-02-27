#include "../s21_test_header.h"

static s21_decimal max_dec = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
// static s21_decimal min_dec = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};

MakeHeader(s21_floor)
MakeHeader(s21_truncate)
MakeHeader(s21_round)
MakeHeader(s21_negate)