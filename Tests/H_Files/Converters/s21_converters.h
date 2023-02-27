#include "../../../C_Api_For_C#_libs/C#_Api_Gen.h"
#include "../../../C_Api_For_C#_libs/C#_Api_Test.h"
#include <check.h>

static s21_decimal max_dec = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
static s21_decimal min_dec = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};