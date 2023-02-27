#include "./H_Files/DecimalGenerator.h"

s21_decimal start = {{0, 0, 0, 0}};
s21_decimal start2 = {{200, 0, 0, 0}};
s21_decimal step = {{10, 0, 0, 0}};

void FF(int i) {
  s21_decimal result;
  result = GenerateDecimal(i, 0);

  char* str = ConvertDecimal(&result);
  printf("stream_1 = [%s]\n", str);
  free(str);
}
void FF1(int i) {
  s21_decimal result;
  result = GenerateDecimal(i, 1);

  char* str = ConvertDecimal(&result);
  printf("stream_2 = [%s]\n", str);
  free(str);
}

int main() {
  Deserialize();
  for (int i = 0; i < 20; i++) {
    FF(i);
    FF1(i);
  }
  CloseGenerators();
}
