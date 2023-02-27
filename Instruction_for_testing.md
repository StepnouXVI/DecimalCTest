# Инструкция по тестированию

## *Тестирование собственных значений*

### Путь до C# приложений

#### Tester

```linux
 ./C#_Api/Tester/DecimalOperationsTester/bin/Release/net7.0/Decimal
 ```

#### Generator

```linux
./C#_Api/Generator/DecimalGenerator/bin/Release/net7.0/DecimalGenerator
```

### *Запрос имеет структуру вида*

| Тип операции     | Строка запроса |
| --------------   | -------------- |
| Бинарная операция | ```application_path number_1 number_2 operation``` |
| Унарная операция |```application_path number_1 operation```|
| Генерация        |```application_path type_of_range start_range end_range step```|

### *Бинарные операции*

| Операция | Обозначение в запросе|
|----|----|
|+   | `SUM`          |
|-   | `SUB`          |
|/   | `DIV`          |
|*   | `MUL`          |
|%   | `MOD`          |
|==  | `EQUAL`        |
|!=  |`NOT_EQUAL`     |
|<   |`LESS`          |
|<=  |`LESS_OR_EQUAL` |

### *Унарные операции*

| Оперция | Обозначение в запросе|
|---------|------------|
|*(-1)              | `NEGATIVE` |
| Floor             | `FLOOR`    |
|Truncate           | `TRUNCATE` |
|Round              |  `ROUND`   |
|decimal => float   |`D2F`       |
|decimal => int     |`D2I`       |
|int => decimal     |`I2D`       |
|float => decimal   |`F2D`       |

### *Генерация значений*

| Тип генерации | Обозначение в запросе | Требуемые аргументы |
|---------------|-----------------------|---------------------|
|Прямой диапазон|`GET_DECIMAL_FROM_RANGE`| number_of point `int`, start `decimal`, step* `decimal`|
|Диапазон вблизи особых точек*|`GET_DECIMAL_NEAR_POINT`|number_of point `int`,point `decimal`, step* `decimal`|

#### *Если шаг не указан, то шаг будет равен 0.01

#### **Для максимального и минимального значения. Стартовая позиция это особая точка со сдвигом на один в допустимую сторону. (для max: max_value - 1)
