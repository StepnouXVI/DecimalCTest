#include "../../H_Files/Unary/s21_unary_test_common.h"

static s21_decimal _start = START;
static s21_decimal _step = STEP;

void run_tests();
int main() {
  int number = NUMBER_OF_SAMPLES;
  AddNewGenerator(&_start, &_step, RANGE);
  AddNewGenerator(&_start, &_step, RANGE);
  Serialize();

  run_tests();

  CloseGenerators();
  ClearSave();

  s21_decimal numberOfSamples;
  get_value_int_s21_decimal(&number, &numberOfSamples);
  get_result_operation_binary(&_step, &numberOfSamples, &_step, DIV_OP);
  AddNewGenerator(&max_dec, &_step, NEAR_POINT);
  AddNewGenerator(&max_dec, &_step, NEAR_POINT);
  Serialize();

  run_tests();

  CloseGenerators();
  ClearSave();
}

void run_tests() {
#ifndef FLOOR
  Run_test_s21_floor(NUMBER_OF_SAMPLES);
#endif
#ifndef NEGATE
  Run_test_s21_negate(NUMBER_OF_SAMPLES);
#endif
#ifndef TRUNCATE
  Run_test_s21_truncate(NUMBER_OF_SAMPLES);
#endif
#ifndef ROUND
  Run_test_s21_round(NUMBER_OF_SAMPLES);
#endif
}