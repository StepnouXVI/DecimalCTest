#include "GeneratorFunctions.h"

#ifndef GENERATOR_H
#define GENERATOR_H

#define MAKE_CLEAR_MANAGER \
  { 0, NULL, NULL, NULL, 0 }
typedef struct GeneratorManager {
  int NumberOfGenerators;
  s21_decimal* Points;
  s21_decimal* Steps;
  int* Types;
  int IsInitialize;
} GeneratorManager;

void AddNewGenerator(const s21_decimal* start, const s21_decimal* step,
                     int typeOfGenerator);
s21_decimal GenerateDecimal(int numberOfValue, int number_of_generator);
void CloseGenerators();
void AllocateManager();
void ResizeManager();

#define CACHE_FILE_NAME "./cache/manager.bin"

void Serialize();
void Deserialize();
void ClearSave();
#endif