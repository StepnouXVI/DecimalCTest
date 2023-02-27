#include "../../H_Files/Converters/s21_converters_common.h"

static s21_decimal max_dec = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

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
#ifdef FLOAT_TO_DECIMAL
  Run_test_s21_from_float_to_decimal(NUMBER_OF_SAMPLES);
#endif

#ifdef INT_TO_DECIMAL
  Run_test_s21_from_int_to_decimal(NUMBER_OF_SAMPLES);
#endif

#ifdef DECIMAL_TO_FLOAT
  Run_test_s21_from_decimal_to_float(NUMBER_OF_SAMPLES);
#endif

#ifdef DECIMAL_TO_INT
  Run_test_s21_from_decimal_to_int(NUMBER_OF_SAMPLES);
#endif
}
