/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int find(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) return 1;
    printf("%d", find(data, n));
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) == 1) {
        if (*n > 30) {
            printf("n/a");
            return 1;
        }
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) {
                printf("n/a");
                return 1;
            }
        }
    } else {
        printf("n/a");
        return 1;
    }

    char temp = getchar();
    if (temp != '\n' && temp != EOF) {
        printf("n/a");
        return 1;
    }

    return 0;
}

double mean(int *a, int n) {  //мат ожидание
    double result = 0;
    for (int *p = a; p - a < n; p++) {
        result += (*p);
    }
    return result / n;
}

double variance(int *a, int n) {  //дисперсия
    double sum = 0;

    for (int *p = a; p - a < n; p++) {
        sum += *p;
    }

    double average = sum / n;
    sum = 0;
    for (int *p = a; p - a < n; p++) {
        sum += (*p - average) * (*p - average);
    }

    return sum / n;
}

int find(int *a, int n) {
    double mean_v = mean(a, n);
    double variance_v = variance(a, n);
    double upper_limit = mean_v + 3 * sqrt(variance_v);

    for (int *p = a; p - a < n; p++) {
        if (*p % 2 == 0 && *p >= mean_v && *p <= upper_limit && *p != 0) {
            // return p - a;  // Возвращаем индекс первого подходящего элемента
            return *p;
        }
    }
    return 0;  // Если ничего не найдено, возвращаем 0
}
