#ifndef POLISH_NOTATION_H
#define POLISH_NOTATION_H

#include <string.h>

#include "get_data.h"
#include "list.h"
#include "stack.h"
List *RPN(List *list);
double solve(List *list, double x);
Element get_result_operand(Element arg1, Element arg2, Element operand);
Element get_result_function(Element arg, Element function);
#endif
