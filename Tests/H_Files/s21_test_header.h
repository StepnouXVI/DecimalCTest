#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef TEST_H
#define TEST_H

#include "../../C_Api_For_C#_libs/C#_Api_Gen.h"
#include "../../C_Api_For_C#_libs/C#_Api_Test.h"
#include "../../C_Api_For_C#_libs/DecimalGenerator.h"


#define START        \
  {                  \
    { 250, 0, 0, 0 } \
  }
#define STEP       \
  {                \
    { 1, 0, 0, 0 } \
  }

#define YELLOW_CONSOLE "\033[1;38;2;255;204;0m"
#define GREEN_CONSOLE "\033[1;32m"
#define STANDARD_CONSOLE "\033[0m"
#define RED_CONSOLE "\033[1;38;2;255;0;0m"
#define NUMBER_OF_SAMPLES 10
#define CASE_NAME_SIZE 20
#define BAND_WIDTH 50
#define ACCURACY 1e-6

#define PrintSuccess                                                        \
  printf(GREEN_CONSOLE);                                                    \
  printf(                                                                   \
      "\n=================================[PASS]==========================" \
      "=======\n");                                                         \
  printf(STANDARD_CONSOLE);

#define PrintFail                                                           \
  printf(RED_CONSOLE);                                                      \
  printf(                                                                   \
      "\n=================================[FAIL]==========================" \
      "=======\n");                                                         \
  printf(STANDARD_CONSOLE);

#define assert_decimal(test_result, origin_result)                     \
  for (int j = 0; j < 4; j++) {                                        \
    ck_assert_uint_eq(test_result.bits32[j], origin_result.bits32[j]); \
  }

#define PrintBinary(number)                             \
  {                                                     \
    size_t size = sizeof(number) * 8;                   \
    char binary[size + 1];                              \
    binary[size] = '\0';                                \
    for (size_t i = 0; i < size; i++) {                 \
      binary[size - 1 - i] = ((128 & number) > 0) + 48; \
      number <<= 1;                                     \
    }                                                   \
    printf("%s", binary);                               \
  }

#define MakeHeader(func) void Run_test_##func(int number_of_tests);

void PrintBinaryDecimal(s21_decimal number);
void PrintInputData_2D(s21_decimal number_1, s21_decimal number_2);
void PrintInputData_1D(s21_decimal number);
void PrintOutputData_2D(int lib_res_status, int sharp_res_status,
                        s21_decimal lib_res, s21_decimal sharp_res);
void PrintStartTest(int number);
void PrintEndTest(int number);
void AssertOutput_2D(int res_1, int res_2, s21_decimal number_1,
                     s21_decimal number_2);
void AssertOutput_2I(int res_1, int res_2, int number_1, int number_2);
void AssertOutput_2F(int res_1, int res_2, float number_1, float number_2);
void PrintInputData_1F(float number);
void PrintInputData_1I(int number);
void PrintOutputData_2F(int lib_res_status, int sharp_res_status, float lib_res,
                        float sharp_res);
void PrintOutputData_2I(int lib_res_status, int sharp_res_status, int lib_res,
                        int sharp_res);

#endif