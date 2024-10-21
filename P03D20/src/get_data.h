#ifndef GET_DATA_H
#define GET_DATA_H

#define START_LENGTH_LINE 32
#define RESIZE_BUFFER_FACTOR 2

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "element.h"
#include "list.h"
#include "polish_notation.h"
List *string_to_list(char *string);
double get_number(char **string);
int get_function(char **string);
Element get_operator(char **string);
Element get_element(char **string);
char *get_string();
int is_function(char *str);
int check_prefix(char *string, char *prefix);

#endif
