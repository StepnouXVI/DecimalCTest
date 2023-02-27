CC = gcc
Flags = -Wall -Wextra -Werror
Source = C_Files/
Headers = H_Files/
Objective = O_Files


update:
	make clean
	make compile
	make compile_sharp

compile: O_Files
	${CC} ${Flags} -O0 -g -c ${Source}*.c
	mv *.o ${Objective}

O_Files:
	mkdir ${Objective}

cppcheck:
	cppcheck -q --enable=all ./${Source}/*.c ./${Headers}/*.h

static_lib: O_Files
	make compile
	ar r ../C_Api_For_C#_libs/libc#_api.a ./${Objective}/*.o
	rm -fr ${Objective}

compile_dynamic_lib: O_Files
	${CC} ${Flags}  -c -fPIC ${Source}*.c
	mv *.o ${Objective}

dynamic_lib: O_Files
	make compile_dynamic_lib
	gcc -shared -o ../C_Api_For_C#_libs/c#_api.so ./${Objective}/*.o
	rm -fr ${Objective}


compile_sharp:
	dotnet build -c Release ../C#_Api/Tester/DecimalOperationsTester
	dotnet build -c Release ../C#_Api/Generator/DecimalGenerator

executeble:compile
	${CC} ${Flags} -O0 -g -c main.c
	mv *.o ${Objective}
	${CC} ${Flags} -O0 -g ./${Objective}/*.o -o test.out


clean:
	rm -f *.o
	rm -f *.out
	rm -fr ${Objective}
	rm -fr Release
	rm -fr ../Sharp_Api/Tester/DecimalOperationsTester/bin/Release
	rm -fr ../Sharp_Api/Generator/DecimalGenerator/bin/Release