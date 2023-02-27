#ifndef REQUEST_CONTROLLER
#define REQUEST_CONTROLLER

#include <stdio.h>
#include <string.h>

#include "ConverterToString.h"
#include "s21_decimal.h"

#define MAKE_CLEAR_CONTROLLER \
  { NULL, NULL }

/// @brief Struct that using for request to C# application.
typedef struct RequestController {
  char* RequestString;
  FILE* AnswerStream;
} RequestController;

/// @brief Sends a request to  C# application. And saves the response stream to
/// the controller.
/// @param controller
void CloseRequest(RequestController* controller);

/// @brief Closes the response stream and cleans up the request's  string.
/// @param controller
void GetRequest(RequestController* controller);

#endif