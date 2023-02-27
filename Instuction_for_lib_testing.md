# Инструкция по тестированию библиотеки

## Сборка тестов

 Производится через `make`.
 Сборка всех тестов:

 ```bash
    make
 ```

 Запуск всех тестов

 ```bash
    make run
 ```

Компиляция конкретного теста:

```bash
    make_update_(имя блока)_test (Имя флагов)=(флаг функции)
```

Пример:

```bash
    make update_math_test MATH_FLAGS=-DADD
```

Имена блоков
|Блок|Имя блока|Имя флагов|
|-|-|-|
|Функции сравнения|`comparators`|`COMP_FLAGS`|
|Бинарные математические|`math`|`MATH_FLAGS`|
|Унарные математические|`unary`|`UNAR_FLAGS`|
|Функции конвертации|`converters`|`CONV_FLAGS`|

Соответствия функций и флагов при компиляции
|Функция|Флаг|
|-|-|
|`add`|`-DADD`|
|`sub`|`-DSUB`|
|`div`|`-DDIV`|
|`mod`|`-DMOD`|
|`mul`|`-DMUL`|
|`==`|`-DEQUAL`|
|`!=`|`-DNOT_EQUAL`|
|`>`|`-DGREATER`|
|`>=`|`-DGREATER_OR_EQUAL`|
|`<`|`-DLESS`|
|`<=`|`-DLESS_OR_EQUAL`|
|`FLOOR`|`-DFLOOR`|
|`ROUND`|`-DROUND`|
|`TRUNCATE`|`-DTRUNCATE`|
|`NEGATE`|`-DNEGATE`|
|`float => decimal`|`-DFLOAT_TO_DECIMAL`|
|`int => decimal`|`-DINT_TO_DECIMAL`|
|`decimal => int`|`-DDECIMAL_TO_INT`|
|`decimal => float`|`-DDECIMAL_TO_FLOAT`|

При использовании с несколькими функциями, их флаги записываются в двойных кавычках через пробел.
Пример:

```bash
    make update_math_test MATH_FLAGS="-DADD -DSUB"
```

## Запуск конкретных блоков

Команда для запуска конкретного набора тестов:

``` bash
    run_(имя блока\набора)_test
```

Пример:

``` bash
    run_math_test
```

## Запуск с `valgrind`
Нужно добавить к прошлому шаблону `_leak`
Пример:

```bash
make run_math_test_leak
```
