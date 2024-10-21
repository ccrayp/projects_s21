all :
	gcc -Wall -Werror -Wextra main_executable_module.c ../data_libs/data_io.c ../data_libs/data_stat.c ../data_module/data_process.c ../yet_another_decision_module/decision.c ../data_libs/sort.c -lm -o ../../build/Quest_3
clean:
	rm -f ../../build/Quest_3
rebuild: clean all
build_with_macro:
	gcc -Wall -Werror -Wextra main_executable_module.c ../data_libs/data_stat.c ../data_module/data_process.c ../yet_another_decision_module/decision.c ../data_libs/sort.c -lm -o ../../build/Quest_4
clean_4:
	rm -f ../../build/Quest_5
rebuild_4: clean_4 build_with_macro

data_stat.a:
	gcc -Wall -Werror -Wextra -c ../data_libs/data_stat.c -o  data_stat.o
	ar rcs data_stat.a data_stat.o
	rm -f data_stat.o
build_with_static:
	gcc -Wall -Werror -Wextra main_executable_module.c ../data_libs/data_io.c ../data_module/data_process.c ../yet_another_decision_module/decision.c ../data_libs/sort.c -lm -L. data_stat.a -o ../../build/Quest_5
clean_5:
	rm -f ../../build/Quest_5
rebuild_5: clean_5 data_stat.a build_with_static

data_process.so:
	gcc -fPIC -c ../data_module/data_process.c -o data_process.o
	gcc -shared -o data_process.so data_process.o
	rm -f data_process.o
build_with_dynamic:
	gcc -Wall -Werror -Wextra main_executable_module.c ../data_libs/data_io.c ../data_libs/data_stat.c ../yet_another_decision_module/decision.c ../data_libs/sort.c -lm -L. data_process.so -o ../../build/Quest_6
clean_6:
	rm -f ../../build/Quest_6
rebuild_6: clean_6 data_process.so build_with_dynamic
clean_all:
	rm -f ../../build/Quest_3
	rm -f ../../build/Quest_4
	rm -f ../../build/Quest_5
	rm -f ../../build/Quest_6
