#include <math.h>
#include <stdio.h>

int fibonacci(int n);

int main() {
    char tc;
    int val;

    if (1 != scanf("%d", &val)) {
        printf("n/a");
        return 0;
    }

    tc = getchar();
    if (tc != EOF && tc != '\n') {
        printf("n/a");
        return 1;
    }

    if (val < 0) {
        printf("n/a");
        return 1;
    } else {
        printf("%d", fibonacci(val));
        return 0;
    }
}

int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    return fibonacci(n - 2) + fibonacci(n - 1);
}
