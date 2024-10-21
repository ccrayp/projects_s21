#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) return 1;
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) == 1) {
        if (*n > 10) {
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

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

int max(int *a, int n) {
    int *p = a;
    int max = *p;
    p++;
    for (; p - a < n; p++) {
        if (*p > max) max = *p;
    }

    return max;
}

int min(int *a, int n) {
    int *p = a;
    int min = *p;
    p++;
    for (; p - a < n; p++) {
        if (*p < min) min = *p;
    }

    return min;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %f %f", max_v, min_v, mean_v, variance_v);
}
