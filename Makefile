CC = gcc
Flags = -Wall -Wextra -Werror
Source = s21_decimal/
INC_LIB = -L. -I.
LIB = C_Api_For_C\#_libs/c\#_api.a
number_of_test = $(shell grep -e "ERROR SUMMARY" -c valgrind_log.log)
number_of_test_with_no_leaks = $(shell grep -e "ERROR SUMMARY: 0" -c valgrind_log.log)

MATH_FLAGS = 
COMP_FLAGS = 
CONV_FLAGS =
UNAR_FLAGS = 


install_sdk:
	wget https://packages.microsoft.com/config/ubuntu/22.10/packages-microsoft-prod.deb -O packages-microsoft-prod.deb
	sudo dpkg -i packages-microsoft-prod.deb
	rm packages-microsoft-prod.deb
	sudo apt-get update && \
  	sudo apt-get install -y dotnet-sdk-7.0
	sudo apt-get update && \
  	sudo apt-get install -y aspnetcore-runtime-7.0

all:C\#_api C_api tests

tests:
	make -f Makefile_tests all
run: run_comparators_test run_math_test run_unary_test run_converters_test

update: clean all

C\#_api:
	make -f Makefile_api compile

update_C\#_api:
	make -f Makefile_api update


decimal:
	make -f Makefile_decimal decimal_static_lib

update_decimal:
	make -f Makefile_decimal update

C_api:
	make -f Makefile_C_api static_lib

C_api_test:
	make -f Makefile_C_api executeble


update_C_api:
	make -f Makefile_C_api update



# TEST
## MATH
update_math_test:
	make -f Makefile_tests update_math ${MATH_FLAGS}
run_math_test:
	Tests/Executeble/math.out
run_math_test_leak:
	valgrind  --leak-check=full Tests/Executeble/math.out 
run_math_test_leak_count:
	valgrind --log-file="valgrind_log.log" --leak-check=full Tests/Executeble/math.out
	@echo NUMBER OF ALL TESTS: $(number_of_test)
	@echo NUMBER OF TESTS WITHOUT LEAKS: $(number_of_test)
## END MATH
## COMP
update_comparators_test:
	make -f Makefile_tests update_comparators
run_comparators_test:
	Tests/Executeble/comparators.out
run_comparators_test_leak:
	valgrind  --leak-check=full Tests/Executeble/comparators.out 
run_comparators_test_leak_count:
	valgrind --log-file="valgrind_log.log" --leak-check=full Tests/Executeble/comparators.out
	@echo NUMBER OF ALL TESTS: $(number_of_test)
	@echo NUMBER OF TESTS WITHOUT LEAKS: $(number_of_test)
## EDN COMP
## CONV
update_unary_test:
	make -f Makefile_tests update_unary
run_unary_test:
	Tests/Executeble/unary.out
run_unary_test_leak:
	valgrind  --leak-check=full Tests/Executeble/unary.out 
run_unary_test_leak_count:
	@echo _TEST
	valgrind --log-file="valgrind_log.log" --leak-check=full Tests/Executeble/unary.out
	@echo NUMBER OF ALL TESTS: $(number_of_test)
	@echo NUMBER OF TESTS WITHOUT LEAKS: $(number_of_test)
## EDN CONV
## UNARY
update_converters_test:
	make -f Makefile_tests update_converters
run_converters_test:
	Tests/Executeble/converters.out
run_converters_test_leak:
	valgrind  --leak-check=full Tests/Executeble/converters.out 
run_converters_test_leak_count:
	@echo UNARY_TEST
	valgrind --log-file="valgrind_log.log" --leak-check=full Tests/Executeble/converters.out
	@echo NUMBER OF ALL TESTS: $(number_of_test)
	@echo NUMBER OF TESTS WITHOUT LEAKS: $(number_of_test)
## EDN UNARY

clean:
	make -f Makefile_tests clean
	make -f Makefile_C_api clean
	make -f Makefile_api clean
	make -f Makefile_decimal clean

