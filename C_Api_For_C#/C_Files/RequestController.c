#include "../H_Files/RequestController.h"

void GetRequest(RequestController* controller) {
  // printf("[%s]\n", controller->RequestString);
  controller->AnswerStream = popen(controller->RequestString, "r");
}

void CloseRequest(RequestController* controller) {
  if (controller->RequestString != NULL) free(controller->RequestString);
  if (controller->AnswerStream != NULL) fclose(controller->AnswerStream);
}
