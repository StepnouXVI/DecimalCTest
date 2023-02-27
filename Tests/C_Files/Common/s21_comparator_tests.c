#include "../../H_Files/s21_binary_operations/Comparators/s21_comparator__operation_common.h"

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
#ifdef EQUAL
  Run_test_s21_is_equal(NUMBER_OF_SAMPLES);
#endif

#ifdef NOT_EQUAL
  Run_test_s21_is_not_equal(NUMBER_OF_SAMPLES);
#endif

#ifdef LESS
  Run_test_s21_is_less(NUMBER_OF_SAMPLES);
#endif

#ifdef LESS_OR_EQUAL
  Run_test_s21_is_less_or_equal(NUMBER_OF_SAMPLES);
#endif

#ifdef GREATER
  Run_test_s21_is_greater(NUMBER_OF_SAMPLES);
#endif

#ifdef GREATER_OR_EQUAL
  Run_test_s21_is_greater_or_equal(NUMBER_OF_SAMPLES);
#endif
}
