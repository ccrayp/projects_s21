#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

Stack *init() { return NULL; }

void push(Stack **stack, int value) {
    Stack *new = (Stack *)malloc(sizeof(Stack));
    if (new != NULL) {
        new->value = value;
        new->prev = *stack;
        *stack = new;
    }
}

int pop(Stack **stack) {
    int value = 0;
    if (*stack != NULL) {
        Stack *top = *stack;
        value = top->value;
        *stack = top->prev;
        free(top);
    }
    return value;
}

void destroy(Stack **stack) {
    while (*stack != NULL) {
        pop(stack);
    }
}
