#include "../H_Files/TestFunctions.h"

#include "../H_Files/Parser.h"
#include "../H_Files/RequestController.h"
#include "../H_Files/RequestControllerFunctionsForTester.h"

int get_result_operation_binary(const s21_decimal *num_1,
                                const s21_decimal *num_2, s21_decimal *result,
                                const char *type_of_operation) {
  RequestController controller =
      ConstructRequestBinary(num_1, num_2, type_of_operation);

  GetRequest(&controller);

  int isNotSuccess = GetInt(controller.AnswerStream);
  if (!isNotSuccess) *result = GetDecimal(controller.AnswerStream);

  CloseRequest(&controller);
  return isNotSuccess;
}

int get_result_operation_comparator(const s21_decimal *num_1,
                                    const s21_decimal *num_2, int *result,
                                    const char *type_of_operation) {
  RequestController controller =
      ConstructRequestBinary(num_1, num_2, type_of_operation);

  GetRequest(&controller);
  int isNotSuccess = GetInt(controller.AnswerStream);
  if (!isNotSuccess) *result = GetBool(controller.AnswerStream);

  CloseRequest(&controller);
  return isNotSuccess;
}

int get_result_operation_unary(const s21_decimal *num, s21_decimal *result,
                               const char *type_of_operation) {
  RequestController controller = ConstructRequestUnary(num, type_of_operation);

  GetRequest(&controller);
  int isNotSuccess = GetInt(controller.AnswerStream);
  if (!isNotSuccess) *result = GetDecimal(controller.AnswerStream);

  CloseRequest(&controller);
  return isNotSuccess;
}

int get_value_int_s21_decimal(int *num, s21_decimal *result) {
  RequestController controller =
      ConstructRequestConvertInt(num, CONVERT_INT_TO_DECIMAL_OP);

  GetRequest(&controller);
  int isNotSuccess = GetInt(controller.AnswerStream);
  if (!isNotSuccess) *result = GetDecimal(controller.AnswerStream);

  CloseRequest(&controller);
  return isNotSuccess;
}

int get_value_float_s21_decimal(float *num, s21_decimal *result) {
  RequestController controller =
      ConstructRequestConvertFloat(num, CONVERT_FLOAT_TO_DECIMAL_OP);

  GetRequest(&controller);
  int isNotSuccess = GetInt(controller.AnswerStream);
  if (!isNotSuccess) *result = GetDecimal(controller.AnswerStream);

  CloseRequest(&controller);
  return isNotSuccess;
}

int get_value_s21_decimal_float(const s21_decimal *num, float *result) {
  RequestController controller =
      ConstructRequestUnary(num, CONVERT_DECIMAL_TO_FLOAT_OP);

  GetRequest(&controller);
  int isNotSuccess = GetInt(controller.AnswerStream);
  if (!isNotSuccess) *result = GetFloat(controller.AnswerStream);

  CloseRequest(&controller);
  return isNotSuccess;
}

int get_value_s21_decimal_int(const s21_decimal *num, int *result) {
  RequestController controller =
      ConstructRequestUnary(num, CONVERT_DECIMAL_TO_INT_OP);

  GetRequest(&controller);
  int isNotSuccess = GetInt(controller.AnswerStream);
  if (!isNotSuccess) *result = GetInt(controller.AnswerStream);

  CloseRequest(&controller);
  return isNotSuccess;
}
