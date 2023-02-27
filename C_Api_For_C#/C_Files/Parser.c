#include "../H_Files/Parser.h"

s21_decimal GetDecimal(FILE* stream) {
  s21_decimal number = {{0, 0, 0, 0}};
  fscanf(stream, "%d %d %d %d", (int*)&number.bits32[0],
         (int*)&number.bits32[1], (int*)&number.bits32[2],
         (int*)&number.bits32[3]);
  return number;
}

float GetFloat(FILE* stream) {
  float number;
  fscanf(stream, "%f", &number);
  return number;
}

int GetInt(FILE* stream) {
  int number;
  fscanf(stream, "%d", &number);
  return number;
}

int GetBool(FILE* stream) {
  int result = 0;
  char outputString[BOOL_STRING_SIZE];
  fscanf(stream, BOOL_STIRNG_READ, outputString);

  if (strcmp(outputString, TRUE) == 0) {
    result = 1;
  }
  return result;
}