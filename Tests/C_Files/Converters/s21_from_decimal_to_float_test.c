#include "../../H_Files/s21_test_header.h" 


#define TEST_OUTPUT                                                      \
  PrintStartTest(_i);                                                    \
  AssertOutput_2F(success_lib, success_sharp, lib_result, sharp_result);    \
  PrintInputData_1D(number);                                                \
  PrintOutputData_2F(success_lib, success_sharp, lib_result, sharp_result); \
  PrintEndTest(_i);

START_TEST(s21_from_decimal_to_float_test) {
  Deserialize();
  s21_decimal number = GenerateDecimal(_i, 0);
  float lib_result;
  float sharp_result;

  int success_sharp = get_value_s21_decimal_float(&number, &sharp_result);

  int success_lib = s21_from_decimal_to_float(number, &lib_result);

  TEST_OUTPUT;

  ck_assert_int_eq(success_lib, success_sharp);
  ck_assert_float_eq_tol(lib_result, sharp_result, ACCURACY);
  CloseGenerators();
}
END_TEST

Suite *Make_s21_from_decimal_to_float_test(int number_of_tests) {
  Suite *suite;
  TCase *tcase;

  suite = suite_create("#s21_from_decimal_to_float");

  tcase = tcase_create("s21_from_decimal_to_float");

  suite_add_tcase(suite, tcase);

  tcase_add_loop_test(tcase, s21_from_decimal_to_float_test, 0,
                      number_of_tests);

  return suite;
}


int Start_test_s21_from_decimal_to_float(int number_of_tests) {
  Suite *suite = Make_s21_from_decimal_to_float_test(number_of_tests);
  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_MINIMAL);

  int number_of_failed_tests = srunner_ntests_failed(runner);

  srunner_free(runner);
  return (number_of_failed_tests == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void Run_test_s21_from_decimal_to_float(int number_of_tests) {
  Start_test_s21_from_decimal_to_float(number_of_tests);
}
