#include "../H_Files/DecimalGenerator.h"
static GeneratorManager _manager = MAKE_CLEAR_MANAGER;

void AddNewGenerator(const s21_decimal* start, const s21_decimal* step,
                     int typeOfGenerator) {
  _manager.IsInitialize = 1;
  _manager.NumberOfGenerators++;
  ResizeManager();

  _manager.Points[_manager.NumberOfGenerators - 1] = *start;
  _manager.Steps[_manager.NumberOfGenerators - 1] = *step;
  _manager.Types[_manager.NumberOfGenerators - 1] = typeOfGenerator;
}

s21_decimal GenerateDecimal(int numberOfValue, int number_of_generator) {
  return GetDecimalFromRange(&_manager.Points[number_of_generator],
                             &_manager.Steps[number_of_generator],
                             numberOfValue,
                             _manager.Types[number_of_generator]);
}

void CloseGenerators() {
  if (_manager.Points != NULL) free(_manager.Points);
  if (_manager.Steps != NULL) free(_manager.Steps);
  if (_manager.Types != NULL) free(_manager.Types);
  GeneratorManager clear = MAKE_CLEAR_MANAGER;
  _manager = clear;
}

void Serialize() {
  FILE* save = fopen(CACHE_FILE_NAME, "wb");
  if (save != NULL) {
    fwrite(&_manager.NumberOfGenerators, sizeof(int), 1, save);
    fwrite(_manager.Points, sizeof(s21_decimal), _manager.NumberOfGenerators,
           save);
    fwrite(_manager.Steps, sizeof(s21_decimal), _manager.NumberOfGenerators,
           save);
    fwrite(_manager.Types, sizeof(int), _manager.NumberOfGenerators, save);
    fclose(save);
  } else {
    printf("[ERROR WITH SAVE MANAGER]\n");
  }
}

void Deserialize() {
  CloseGenerators();
  FILE* save = fopen(CACHE_FILE_NAME, "rb");

  if (save != NULL) {
    fread(&_manager.NumberOfGenerators, sizeof(int), 1, save);
    AllocateManager();
    fread(_manager.Points, sizeof(s21_decimal), _manager.NumberOfGenerators,
          save);

    fread(_manager.Steps, sizeof(s21_decimal), _manager.NumberOfGenerators,
          save);

    fread(_manager.Types, sizeof(int), _manager.NumberOfGenerators, save);

    fclose(save);

  } else {
    printf("[ERROR WITH READ MANAGER]\n");
  }
}

void ResizeManager() {
  _manager.Points = (s21_decimal*)realloc(
      _manager.Points, (_manager.NumberOfGenerators) * sizeof(s21_decimal));
  _manager.Steps = (s21_decimal*)realloc(
      _manager.Steps, (_manager.NumberOfGenerators) * sizeof(s21_decimal));
  _manager.Types = (int*)realloc(_manager.Types,
                                 (_manager.NumberOfGenerators) * sizeof(int));
}

void AllocateManager() {
  _manager.Points =
      (s21_decimal*)malloc((_manager.NumberOfGenerators) * sizeof(s21_decimal));
  _manager.Steps =
      (s21_decimal*)malloc((_manager.NumberOfGenerators) * sizeof(s21_decimal));
  _manager.Types = (int*)malloc((_manager.NumberOfGenerators) * sizeof(int));
}

void ClearSave() {
  FILE* save = fopen(CACHE_FILE_NAME, "wb");
  if (save == NULL) {
    printf("[ERROR WITH CLEAN  SAVE MANAGER]\n");
  } else
    fclose(save);
}