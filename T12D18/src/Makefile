print_module:
	gcc -Wall -Werror -Wextra print_module.c main_module_entry_point.c -D Q1 -o ../build/Quest_1
clean_1:
	rm -f ../build/Quest_1
rebuild_1: clean_1 print_module

documentation_module:
	gcc -Wall -Werror -Wextra print_module.c main_module_entry_point.c documentation_module.c -D Q2 -o ../build/Quest_2
clean_2:
	rm -f ../build/Quest_2
rebuild_2: clean_2 documentation_module

bst_create_test:
	gcc -Wall -Werror -Wextra bst.c bst_create_test.c -o ../build/Quest_3
clean_3:
	rm -f ../build/Quest_4
rebuild_3: clean_3 bst_create_test

bst_insert_test:
	gcc -Wall -Werror -Wextra bst.c bst_insert_test.c -o ../build/Quest_4
clean_4:
	rm -f ../build/Quest_4
rebuild_4: clean_4 bst_insert_test

bst_traverse_test:
	gcc -Wall -Werror -Wextra bst.c bst_traverse_test.c -o ../build/Quest_5
clean_5:
	rm -f ../build/Quest_5
rebuild_5: clean_5 bst_insert_test
