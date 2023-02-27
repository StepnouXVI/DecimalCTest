#include "../H_Files/GeneratorFunctions.h"

s21_decimal GetDecimalFromRange(const s21_decimal* point,
                                const s21_decimal* step, int numberOfValue,
                                int typeOfGenerator) {
  RequestController controller;
  char _typeOfGenerator[MAX_OPERATION_SIZE];
  if (typeOfGenerator == NEAR_POINT)
    strcpy(_typeOfGenerator, GET_DECIMAL_NEAR_POINT);
  else
    strcpy(_typeOfGenerator, GET_DECIMAL_FROM_RANGE);

  controller = ConstructRequestForDecimalFromRange(point, step, numberOfValue,
                                                   _typeOfGenerator);
  GetRequest(&controller);

  s21_decimal result = GetDecimal(controller.AnswerStream);

  CloseRequest(&controller);

  return result;
}
