#include "stack.h"

#include <stdio.h>

int main() {
    int result = 1;
    Stack *stack = init();
    push(&stack, 3);
    if (stack->value != 3) result = 0;
    push(&stack, 2);
    if (stack->value != 2) result = 0;
    push(&stack, 1);
    if (stack->value != 1) result = 0;
    pop(&stack);
    if (stack->value != 2) result = 0;

    if (result) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    destroy(&stack);

    return 0;
}
