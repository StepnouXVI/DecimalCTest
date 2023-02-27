#include "../H_Files/RequestControllerFunctionsForTester.h"

RequestController ConstructRequestBinary(const s21_decimal* num1,
                                         const s21_decimal* num2,
                                         const char* typeOfOperation) {
  RequestController RequestController = MAKE_CLEAR_CONTROLLER;
  RequestController.RequestString =
      (char*)calloc(sizeof(char), STRING_SIZE_FOR_BINARY);

  char* number1 = ConvertDecimal(num1);
  char* number2 = ConvertDecimal(num2);

  strcat(RequestController.RequestString, SHARP_TESTER);
  strcat(RequestController.RequestString, " ");
  strcat(RequestController.RequestString, number1);
  strcat(RequestController.RequestString, " ");
  strcat(RequestController.RequestString, number2);
  strcat(RequestController.RequestString, " ");
  strcat(RequestController.RequestString, typeOfOperation);

  free(number1);
  free(number2);

  return RequestController;
}

RequestController ConstructRequestUnary(const s21_decimal* num,
                                        const char* typeOfOperation) {
  RequestController RequestController = MAKE_CLEAR_CONTROLLER;
  RequestController.RequestString =
      (char*)calloc(sizeof(char), STRING_SIZE_FOR_BINARY);

  char* number = ConvertDecimal(num);
  strcat(RequestController.RequestString, SHARP_TESTER);
  strcat(RequestController.RequestString, " ");
  strcat(RequestController.RequestString, number);
  strcat(RequestController.RequestString, " ");
  strcat(RequestController.RequestString, typeOfOperation);

  free(number);

  return RequestController;
}

RequestController ConstructRequestConvertFloat(float* num,
                                               const char* typeOfOperation) {
  RequestController RequestController = MAKE_CLEAR_CONTROLLER;
  RequestController.RequestString =
      (char*)calloc(sizeof(char), STRING_SIZE_FOR_UNARY);
  char* number = ConvertFloat(num);

  strcat(RequestController.RequestString, SHARP_TESTER);
  strcat(RequestController.RequestString, " ");
  strcat(RequestController.RequestString, number);
  strcat(RequestController.RequestString, " ");
  strcat(RequestController.RequestString, typeOfOperation);

  free(number);

  return RequestController;
}

RequestController ConstructRequestConvertInt(int* num,
                                             const char* typeOfOperation) {
  RequestController RequestController = MAKE_CLEAR_CONTROLLER;
  RequestController.RequestString =
      (char*)calloc(sizeof(char), STRING_SIZE_FOR_UNARY);

  char* number = ConvertInt(num);
  strcat(RequestController.RequestString, SHARP_TESTER);
  strcat(RequestController.RequestString, " ");
  strcat(RequestController.RequestString, number);
  strcat(RequestController.RequestString, " ");
  strcat(RequestController.RequestString, typeOfOperation);

  free(number);

  return RequestController;
}