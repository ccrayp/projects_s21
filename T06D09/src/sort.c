#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int a[NMAX], n = NMAX;
    if (input(a, n) == 0) {
        sort(a, n);
        output(a, n);
        return 0;
    } else {
        printf("n/a");
    }
    return 1;
}

int input(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (scanf("%d", p) != 1) return 1;
    }

    int temp = getchar();
    if (temp != '\n' && temp != EOF) return 1;

    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
}

void sort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
