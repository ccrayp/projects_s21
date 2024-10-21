#include "polish_notation.h"

List *RPN(List *list) {
    Stack *stack = stack_init();
    List *answer = list_init();
    int out = 0;

    for (int ind = 0; ind < list->size; ind++) {
        if (!out) {
            Element element = list_get(list, ind);
            if ((element.type == VARIABLE) || (element.type == NUMBER) || (element.type == ERROR)) {
                list_add(answer, element);
                if (element.type == ERROR) {
                    stack_destroy(stack);
                    out = 1;
                }
            } else if ((element.type == OPEN_PARENTHESIS) || (element.type == FUNCTION)) {
                stack_push(stack, element);
            } else if (element.type == CLOSE_PARENTHESIS) {
                while (!stack_is_empty(stack) && (stack_get(stack).type != OPEN_PARENTHESIS)) {
                    list_add(answer, stack_get(stack));
                    stack_pop(stack);
                }
                if (!stack_is_empty(stack))
                    stack_pop(stack);
                else {
                    element.type = ERROR;
                    list_add(list, element);
                    out = 1;
                }
            } else if (element.type == OPERATOR) {
                while (!stack_is_empty(stack) && (stack_get(stack).priority > element.priority)) {
                    list_add(answer, stack_get(stack));
                    stack_pop(stack);
                }
                stack_push(stack, element);
            }
        }
    }
    if (!out) {
        while (!stack_is_empty(stack)) {
            list_add(answer, stack_get(stack));
            stack_pop(stack);
        }
        stack_destroy(stack);
    }

    return answer;
}
double solve(List *list, double x) {
    int error = 0;
    double answer;
    Stack *stack = stack_init();

    for (int i = 0; !error && (i < list->size); i++) {
        Element element_1, element_2, element_3;
        element_1 = list_get(list, i);
        if (element_1.type == NUMBER) {
            stack_push(stack, element_1);
        } else if (element_1.type == VARIABLE) {
            element_3.type = NUMBER;
            element_3.real_value = x;
            element_3.priority = 0;
            element_3.value = 0;
            stack_push(stack, element_3);
        } else if (element_1.type == OPERATOR) {
            element_3 = stack_get(stack);
            stack_pop(stack);
            element_2 = stack_get(stack);
            stack_pop(stack);
            stack_push(stack, get_result_operand(element_2, element_3, element_1));
            if (stack_get(stack).type == ERROR) error++;
        } else if (element_1.type == FUNCTION) {
            element_2 = stack_get(stack);
            stack_pop(stack);
            stack_push(stack, get_result_function(element_2, element_1));
            if (stack_get(stack).type == ERROR) error++;
        } else {
            stack_push(stack, element_1);
            error++;
        }
    }

    if (stack_get(stack).type == ERROR)
        answer = NAN;
    else
        answer = stack_get(stack).real_value;
    stack_destroy(stack);

    return answer;
}

Element get_result_operand(Element arg1, Element arg2, Element operand) {
    Element answer;
    answer.type = NUMBER;
    answer.priority = 0;
    answer.value = 0;
    if (operand.value == PLUS)
        answer.real_value = arg1.real_value + arg2.real_value;
    else if (operand.value == MINUS)
        answer.real_value = arg1.real_value - arg2.real_value;
    else if (operand.value == MULTIPLICATION)
        answer.real_value = arg1.real_value * arg2.real_value;
    else {
        if (arg2.real_value == 0)
            answer.type = ERROR;
        else
            answer.real_value = arg1.real_value / arg2.real_value;
    }

    return answer;
}

Element get_result_function(Element arg, Element function) {
    Element answer;
    answer.type = NUMBER;
    answer.priority = 0;
    answer.value = 0;
    if (function.value == UNARY_MINUS) answer.real_value = (-1) * arg.real_value;
    if (function.value == SIN) answer.real_value = sin(arg.real_value);
    if (function.value == COS) answer.real_value = cos(arg.real_value);
    if (function.value == LN) {
        if (arg.real_value <= 0)
            answer.type = ERROR;
        else
            answer.real_value = log(arg.real_value);
    } else if (function.value == SQRT) {
        if (arg.real_value < 0)
            answer.type = ERROR;
        else
            answer.real_value = sqrt(arg.real_value);
    } else if (function.value == TG) {
        if (cos(arg.real_value) == 0)
            answer.type = ERROR;
        else
            answer.real_value = sin(arg.real_value) / cos(arg.real_value);
    } else if (function.value == CTG) {
        if (sin(arg.real_value) == 0)
            answer.type = ERROR;
        else
            answer.real_value = cos(arg.real_value) / sin(arg.real_value);
    }

    return answer;
}
