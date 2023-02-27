#include "../../H_Files/s21_test_header.h"
#include "math.h"
void PrintEndTest(int number) {
  printf(
      "============================{ \033[4mEND TEST № %d\033[0m "
      "}============================\n\n",
      number);
  printf(YELLOW_CONSOLE);
  for (int i = 0; i < 153; i++) {
    printf("-");
  }
  printf(STANDARD_CONSOLE);
  printf("\n\n");
}

void PrintStartTest(int number) {
  printf(
      "=============================={ \033[4mTEST № %d\033[0m "
      "}==============================\n",
      number);
  printf(STANDARD_CONSOLE);
}

void PrintBinaryDecimal(s21_decimal number) {
  printf("[  ");
  for (int i = 3; i >= 0; i--) {
    u_int32_t n = number.bits32[i];
    PrintBinary(n);
    printf("  ");
  }
  printf("]\n");
}

void PrintInputData_2D(s21_decimal number_1, s21_decimal number_2) {
  printf("\033[4;1;3;38;2;29;172;214mInput data\033[0m:\n");
  printf("  Number_1 = ");
  PrintBinaryDecimal(number_1);

  printf("  Number_2 = ");
  PrintBinaryDecimal(number_2);
}

void PrintInputData_1D(s21_decimal number) {
  printf("\033[4;1;3;38;2;29;172;214mInput data\033[0m:\n");
  printf("  Number   = ");
  PrintBinaryDecimal(number);
}

void PrintInputData_1F(float number) {
  printf("\033[4;1;3;38;2;29;172;214mInput data\033[0m:\n");
  printf("  Number   = %f", number);
}

void PrintInputData_1I(int number) {
  printf("\033[4;1;3;38;2;29;172;214mInput data\033[0m:\n");
  printf("  Number = %d", number);
}

void PrintOutputData_2D(int lib_res_status, int sharp_res_status,
                     s21_decimal lib_res, s21_decimal sharp_res) {
  printf("\033[4;1;3;38;2;204;132;0mOutput data\033[0m:\n");
  printf("  LIB  = [%d] ", lib_res_status);
  PrintBinaryDecimal(lib_res);
  printf("  C#   = [%d] ", sharp_res_status);
  PrintBinaryDecimal(sharp_res);
}

void PrintOutputData_2I(int lib_res_status, int sharp_res_status, int lib_res,
                     int sharp_res) {
  printf("\033[4;1;3;38;2;204;132;0mOutput data\033[0m:\n");
  printf("  LIB = %d %d\n", lib_res_status, lib_res);
  printf("  C# = %d %d\n", sharp_res_status, sharp_res);
}

void PrintOutputData_2F(int lib_res_status, int sharp_res_status, float lib_res,
                     float sharp_res) {
  printf("\033[4;1;3;38;2;204;132;0mOutput data\033[0m:\n");
  printf("  LIB = %d %f\n", lib_res_status, lib_res);
  printf("  C# = %d %f\n", sharp_res_status, sharp_res);
}

void AssertOutput_2D(int res_1, int res_2, s21_decimal number_1,
                  s21_decimal number_2) {
  int isEqual = 0;
  if(res_1 == res_2 && res_1 == 0)
  get_result_operation_comparator(&number_1, &number_2, &isEqual, EQUAL_OP);
  else
    isEqual = 1;
  if (res_1 != res_2 || !isEqual) {
    PrintFail
  } else {
    PrintSuccess
  }
}

void AssertOutput_2I(int res_1, int res_2, int number_1, int number_2) {
  if (res_1 != res_2 || number_1 != number_2) {
    PrintFail
  } else {
    PrintSuccess
  }
}

void AssertOutput_2F(int res_1, int res_2, float number_1, float number_2) {
  if (res_1 != res_2 || fabs(number_1 - number_2) > ACCURACY) {
    PrintFail
  } else {
    PrintSuccess
  }
}
