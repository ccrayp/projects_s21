#include "data_io.h"

void input(double **data, int *n, int *flag) {
    if (scanf("%d", n) != 1) {
        printf("n/a");
        *flag = 0;
    }

    if (*n < 0) {
        printf("n/a");
        *flag = 0;
    }

    *data = (double *)malloc(*n * sizeof(double));
    if (*data == NULL) {
        printf("n/a");
        *flag = 0;
    }

    for (int i = 0; i < *n && *flag; i++) {
        if (scanf("%lf", &(*data)[i]) != 1) {
            printf("n/a");
            *flag = 0;
        }
    }
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            printf("%.2lf ", data[i]);
        else
            printf("%.2lf", data[i]);
    }
}
