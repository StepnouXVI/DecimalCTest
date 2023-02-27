#include "../../H_Files/s21_test_header.h"

#define TEST_OUTPUT                                                         \
  PrintStartTest(_i);                                                       \
  AssertOutput_2D(success_lib, success_sharp, lib_result, sharp_result);    \
  PrintInputData_1I(number);                                                \
  PrintOutputData_2D(success_lib, success_sharp, lib_result, sharp_result); \
  PrintEndTest(_i);

START_TEST(s21_from_int_to_decimal_test) {
  s21_decimal sharp_result;
  s21_decimal lib_result;
  int number = _i;

  int success_sharp = get_value_int_s21_decimal(&number, &sharp_result);
  int success_lib = s21_from_int_to_decimal(number, &lib_result);

  TEST_OUTPUT;

  ck_assert_int_eq(success_lib, success_sharp);
  assert_decimal(lib_result, sharp_result);
}
END_TEST

Suite *Make_s21_from_int_to_decimal_test(int number_of_tests) {
  Suite *suite;
  TCase *tcase;

  suite = suite_create("s21_from_int_to_decimal");

  tcase = tcase_create("s21_from_int_to_decimal");

  suite_add_tcase(suite, tcase);

  tcase_add_loop_test(tcase, s21_from_int_to_decimal_test, 0, number_of_tests);

  return suite;
}

int Start_test_s21_from_int_to_decimal(int number_of_tests) {
  Suite *suite = Make_s21_from_int_to_decimal_test(number_of_tests);
  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_MINIMAL);

  int number_of_failed_tests = srunner_ntests_failed(runner);

  srunner_free(runner);
  return (number_of_failed_tests == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void Run_test_s21_from_int_to_decimal(int number_of_tests) {
  Start_test_s21_from_int_to_decimal(number_of_tests);
}
