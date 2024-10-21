#ifndef STACK_H
#define STACK_H

#include "list.h"

typedef Element Data;

typedef struct StackItem {
    Data value;
    struct StackItem *prev;
} StackItem;

typedef struct Stack {
    StackItem *first;
    StackItem *last;
} Stack;

Stack *stack_init();
void stack_pop(Stack *stack);
int stack_is_empty(Stack *stack);
void stack_push(Stack *stack, Data value);
void stack_destroy(Stack *stack);
Data stack_get(Stack *stack);

#endif
