#include "../../H_Files/s21_binary_operations/math/s21_binary_operation_common.h"

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
#ifdef ADD
  Run_test_s21_add(NUMBER_OF_SAMPLES);
#endif

#ifdef SUB
  Run_test_s21_sub(NUMBER_OF_SAMPLES);
#endif

#ifdef MUL
  Run_test_s21_mul(NUMBER_OF_SAMPLES);

#endif

#ifdef DIV
  Run_test_s21_div(NUMBER_OF_SAMPLES);
#endif

#ifdef MOD
  Run_test_s21_mod(NUMBER_OF_SAMPLES);
#endif
}
