#include "../libs/s21_decimal.h"

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
void CloseGenerator();