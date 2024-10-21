#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    struct Stack *prev;
    int value;
} Stack;

Stack *init();
void push(Stack **stack, int value);
int pop(Stack **stack);
void destroy(Stack **stack);

#endif
