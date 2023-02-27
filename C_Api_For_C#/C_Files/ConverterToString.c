#include "../H_Files/ConverterToString.h"

char *ConvertDecimal(const s21_decimal *number) {
  int sharp_decimal[4];
  char *string = (char *)malloc(sizeof(char) * SIZE_OF_STRING_FOR_CONVERT);
  for (int i = 0; i < 4; i++) {
    sharp_decimal[i] = *((int *)&(number->bits32[i]));
  }
  sprintf(string, "%d %d %d %d", sharp_decimal[0], sharp_decimal[1],
          sharp_decimal[2], sharp_decimal[3]);
  return string;
}

char *ConvertFloat(float *number) {
  char *string = (char *)malloc(sizeof(char) * SIZE_OF_STRING_FOR_CONVERT);
  sprintf(string, "%f", *number);
  return string;
}

char *ConvertInt(int *number) {
  char *string = (char *)malloc(sizeof(char) * SIZE_OF_STRING_FOR_CONVERT);
  sprintf(string, "%d", *number);
  return string;
}