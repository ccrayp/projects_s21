#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n);
void input(double ***matrix, int *n) void output(double determinant);

int main() {
    double **matrix;
    int n;

    input(&matrix, &n);
    if (matrix == NULL) {
        printf("n/a");
        return 0;
    }

    output(det(matrix, n));

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

double det(double **matrix, int n) {
    double determinant = 0;
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    for (int x = 0; x < n; x++) {
        double **submatrix = (double **)malloc((n - 1) * sizeof(double *));
        for (int i = 0; i < n - 1; i++) {
            submatrix[i] = (double *)malloc((n - 1) * sizeof(double));
        }
        for (int i = 1; i < n; i++) {
            int sub_j = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) {
                    continue;
                }
                submatrix[i - 1][sub_j] = matrix[i][j];
                sub_j++;
            }
        }
        determinant += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * det(submatrix, n - 1);
        for (int i = 0; i < n - 1; i++) {
            free(submatrix[i]);
        }
        free(submatrix);
    }
    return determinant;
}

void input(double ***matrix, int *n) {
    if (scanf("%d", n) != 1 || *n <= 0) {
        *matrix = NULL;
        return;
    }

    if (scanf("%d", n) != 1 || *n <= 0) {
        *matrix = NULL;
        return;
    }

    *matrix = (double **)malloc(*n * sizeof(double *));
    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (double *)malloc(*n * sizeof(double));
        for (int j = 0; j < *n; j++) {
            if (scanf("%lf", &(*matrix)[i][j]) != 1) {
                *matrix = NULL;
                return;
            }
        }
    }
}

void output(double determinant) {
    if (determinant == 0.0) {
        printf("0.000000");
    } else {
        printf("%.6f", determinant);
    }
}
