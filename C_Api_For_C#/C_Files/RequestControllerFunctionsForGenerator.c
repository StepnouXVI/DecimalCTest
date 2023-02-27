#include "../H_Files/RequestControllerFunctionsForGenerator.h"

RequestController ConstructRequestForDecimalFromRange(
    const s21_decimal* start, const s21_decimal* step, int numberOfValue,
    const char* type_of_range) {
  RequestController RequestController = MAKE_CLEAR_CONTROLLER;
  RequestController.RequestString =
      (char*)calloc(sizeof(char), STRING_SIZE_FOR_RANGE);

  char* _start = ConvertDecimal(start);
  char* _number = ConvertInt(&numberOfValue);

  strcat(RequestController.RequestString, SHARP_GENERATOR);
  strcat(RequestController.RequestString, " ");
  strcat(RequestController.RequestString, type_of_range);
  strcat(RequestController.RequestString, " ");
  strcat(RequestController.RequestString, _number);
  strcat(RequestController.RequestString, " ");
  strcat(RequestController.RequestString, _start);
  if (step != NULL) {
    char* _step = ConvertDecimal(step);
    strcat(RequestController.RequestString, " ");
    strcat(RequestController.RequestString, _step);
    free(_step);
  }
  free(_number);
  free(_start);

  return RequestController;
}
