#include "stack.h"

#include <stdlib.h>

Stack *stack_init() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack) {
        stack->first = NULL;
        stack->last = NULL;
    }

    return stack;
}

void stack_pop(Stack *stack) {
    if (!stack) return;

    if (!stack_is_empty(stack)) {
        StackItem *last_item = stack->last;
        stack->last = stack->last->prev;
        if (last_item == stack->first) stack->first = NULL;
        free(last_item);
    }
}

void stack_push(Stack *stack, Data value) {
    if (!stack) return;
    StackItem *item = (StackItem *)malloc(sizeof(StackItem));
    item->prev = NULL;
    item->value = value;

    if (stack_is_empty(stack)) {
        stack->first = item;
        stack->last = item;
    } else {
        item->prev = stack->last;
        stack->last = item;
    }
}

int stack_is_empty(Stack *stack) {
    int result = 1;
    if (stack) {
        if (stack->last != NULL) result = 0;
    }
    return result;
}

Data stack_get(Stack *stack) { return stack->last->value; }

void stack_destroy(Stack *stack) {
    if (!stack) return;
    while (!stack_is_empty(stack)) stack_pop(stack);
    free(stack);
}
