#include <check.h>

#include "../../s21_test_header.h"

#define TEST_OUTPUT                                                         \
  PrintStartTest(_i);                                                       \
  AssertOutput_2I(success_lib, success_sharp, lib_result, sharp_result);    \
  PrintInputData_2D(number_1, number_2);                                    \
  PrintOutputData_2I(success_lib, success_sharp, lib_result, sharp_result); \
  PrintEndTest(_i);

#define BINARY_ARITHMETIC_TEST(func, operation_type)          \
  START_TEST(func##_test) {                                   \
    Deserialize();                                            \
    s21_decimal number_1 = GenerateDecimal(_i, 0);            \
    s21_decimal number_2 = GenerateDecimal(_i, 1);            \
    int lib_result;                                           \
    int sharp_result;                                         \
    int success_lib = 0;                                      \
                                                              \
    int success_sharp = get_result_operation_comparator(      \
        &number_1, &number_2, &sharp_result, operation_type); \
                                                              \
    lib_result = func(number_1, number_2);                    \
                                                              \
    TEST_OUTPUT;                                              \
                                                              \
    ck_assert_uint_eq(lib_result, sharp_result);              \
    CloseGenerators();                                        \
  }                                                           \
  END_TEST

#define MAKE_SUITE_FOR_FUNCTION(func)                            \
  Suite *Make_##func##_test(int number_of_tests) {               \
    Suite *suite;                                                \
    TCase *tcase;                                                \
                                                                 \
    suite = suite_create(#func);                                 \
                                                                 \
    tcase = tcase_create(#func);                                 \
                                                                 \
    suite_add_tcase(suite, tcase);                               \
                                                                 \
    tcase_add_loop_test(tcase, func##_test, 0, number_of_tests); \
                                                                 \
    return suite;                                                \
  }

#define StarterForTest(func, operation_type)                              \
  BINARY_ARITHMETIC_TEST(func, operation_type)                            \
  MAKE_SUITE_FOR_FUNCTION(func)                                           \
                                                                          \
  int Start_test_##func(int number_of_tests) {                            \
    Suite *suite = Make_##func##_test(number_of_tests);                   \
    SRunner *runner = srunner_create(suite);                              \
                                                                          \
    srunner_run_all(runner, CK_MINIMAL);                                  \
                                                                          \
    int number_of_failed_tests = srunner_ntests_failed(runner);           \
                                                                          \
    srunner_free(runner);                                                 \
    return (number_of_failed_tests == 0) ? EXIT_SUCCESS : EXIT_FAILURE; \
  }                                                                       \
                                                                          \
  void Run_test_##func(int number_of_tests) {                             \
    Start_test_##func(number_of_tests);                                   \
  }
