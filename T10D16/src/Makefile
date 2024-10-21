all:
	gcc -Wall -Wextra -Werror s21_string.c s21_string_test.c -D Q1 -D Q2 -D Q3 -D Q4 -D Q5 -D Q6 -D Q7 -o ../build/Test_string_h
clean:
	rm -f ../build/Test_string_h
rebuild:
	rm -f ../build/Test_string_h
	gcc -Wall -Wextra -Werror s21_string.c s21_string_test.c -D Q1 -D Q2 -D Q3 -D Q4 -D Q5 -D Q6 -D Q7 -o ../build/Test_string_h

strlen_tests:
	gcc -Wall -Wextra -Werror s21_string.c s21_string_test.c -D Q1 -o ../build/Quest_1
strlen_tests_clean:
	rm -f ../build/Quest_1
strlen_tests_rebuild: strlen_tests_clean strlen_tests

strcmp_tests:
	gcc -Wall -Wextra -Werror s21_string.c s21_string_test.c -D Q2 -o ../build/Quest_2
strcmp_tests_clean:
	rm -f ../build/Quest_2
strcmp_tests_rebuild: strcmp_tests_clean strcmp_tests

strcpy_tests:
	gcc -Wall -Wextra -Werror s21_string.c s21_string_test.c -D Q3 -o ../build/Quest_3
strcpy_tests_clean:
	rm -f ../build/Quest_3
strcpy_tests_rebuild: strcpy_tests_clean strcpy_tests

strcat_tests:
	gcc -Wall -Wextra -Werror s21_string.c s21_string_test.c -D Q4 -o ../build/Quest_4
strcat_tests_clean:
	rm -f ../build/Quest_4
strcat_tests_rebuild: strcat_tests_clean strcat_tests

strch_tests:
	gcc -Wall -Wextra -Werror s21_string.c s21_string_test.c -D Q5 -o ../build/Quest_5
strch_tests_clean:
	rm -f ../build/Quest_5
strch_tests_rebuild: strch_tests_clean strch_tests

strstr_tests:
	gcc -Wall -Wextra -Werror s21_string.c s21_string_test.c -D Q6 -o ../build/Quest_6
strstr_tests_clean:
	rm -f ../build/Quest_6
strstr_tests_rebuild: strstr_tests_clean strstr_tests

strtok_tests:
	gcc -Wall -Wextra -Werror s21_string.c s21_string_test.c -D Q7 -o ../build/Quest_7
strtok_tests_clean:
	rm -f ../build/Quest_6
strtok_tests_rebuild: strtok_tests_clean strtok_tests

Quest_8_build:
	gcc -Wall -Werror -Wextra s21_string.c text_processor.c -o ../build/build_Quest_8
Quest_8_clean:
	rm -f ../build/Quest_8_build
Quest_8_rebuild: Quest_8_clean Quest_8_build
