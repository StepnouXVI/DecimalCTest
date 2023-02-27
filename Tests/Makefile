CC = gcc
Flags = -Wall -Wextra -Werror

SOURCE = C_Files/
COMAPARATORS = $(SOURCE)Comparators/
MATH = $(SOURCE)Math/
CONVERTERS = $(SOURCE)/Converters/

HEADERS= H_Files/
OBJECT = O_Files/
API_TESTING_LIB = -L../C_Api_For_C\#_libs -lc\#_api
DECIMAL_LIB = -L../libs -ls21_decimal 
EXECUTEBLE_DIR = Executebale/

COMMON_O = $(OBJECT)/s21_test.o
CHECK_LIB = -lcheck -lrt -lpthread -lm -lsubunit

# ifeq ($(OS), Darwin)
# else
# 	CHECK_LIB += -lrt -lpthread -lm -lsubunit
# endif






compile_comparator:common_o
	$(CC) $(Flags) -c $(COMAPARATORS)*.c
	mv ./*.o ${OBJECT}

comparator:
	$(CC) $(Flags) $(API_TESTING_LIB) $(DECIMAL_LIB) $(CHECK_LIB) ./*.o -o ./$(EXECUTEBLE_DIR)comparators.out 

compile_math:clean common_o 
	$(CC) $(Flags) -c $(MATH)*.c
	mv ./*.o ${OBJECT}

math:compile_math
	$(CC) $(Flags)  ${OBJECT}*.o -o math.out $(API_TESTING_LIB) $(DECIMAL_LIB) $(CHECK_LIB) 
	make clean_o




common_o:
	$(CC) $(Flags) $(CHECK_LIB) -c $(SOURCE)s21_test.c 

update:
	make clean
	make compile

compile: O_Files
	$(CC) $(Flags)  -c $(Source)*.c 
	mv *.o $(Objective)

compile_executable_all: Executeble
	$(CC) $(Flags) 

executeble:
	mkdir Executeble
O_Files:
	mkdir $(Objective)

cppcheck:
	cppcheck -q --enable=all ./$(Source)/*.c ./$(Headers)/*.h

clean_o:
	rm -fr $(Objective)

clean:clean_o
	rm -f *.o
	rm -f *.out
	rm -f *.a