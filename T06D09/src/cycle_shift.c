#include <stdio.h>

#define NMAX 10

int input(int *a, int *n, int *c);
void output(int *a, int n);
void shift_left(int *a, int n, int c);
void shift_right(int *a, int n, int c);

int main() {
    int n = 0, a[NMAX], c = 0;

    if (input(a, &n, &c) == 0) {
        if (c < 0)
            shift_right(a, n, c);
        else
            shift_left(a, n, c);
        output(a, n);
    } else
        printf("n/a");

    return 0;
}

int input(int *a, int *n, int *c) {
    if (scanf("%d", n) != 1) return 1;
    if (*n < 0) return 1;

    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) return 1;
    }

    if (scanf("%d", c) != 1) return 1;

    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
}

void shift_left(int *a, int n, int c) {
    c %= 10;
    for (int i = 0; i < c; i++) {
        int temp = a[0];
        for (int j = 0; j < n - 1; j++) {
            a[j] = a[j + 1];
        }
        a[n - 1] = temp;
    }
}

void shift_right(int *a, int n, int c) {
    c *= -1;
    c %= 10;
    for (int i = 0; i < c; i++) {
        int temp = a[n - 1];
        for (int j = n - 1; j > -1; j--) {
            a[j] = a[j - 1];
        }
        a[0] = temp;
    }
}
