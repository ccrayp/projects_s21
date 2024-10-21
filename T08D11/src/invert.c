#include <stdio.h>
#include <stdlib.h>

void input(double **matrix, int *n);
void output(double **matrix, int n);
double det(double **matrix, int n);
int transpose(double ***matrix, int n, int m);

int main() {
    double **m = NULL, n = 0;
    input_matrix();
    double determinant = det(m, n);
    transpose(&m, n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = ((double)1 / determinant) * m[i][j];
        }
    }
    output(m, n);
}

int input_matrix(const int r, const int c, int **matrix) {
    char ch;
    if (!matrix) return 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (scanf("%d", matrix[i] + j) != 1) return 1;
        }
    }
    if (((ch = getchar()) != (int)'\n') && (ch != (int)EOF)) return 1;

    return 0;
}

int transpose(int ***matrix, int m, int n) {
    int **values;
    if (create_matrix(&values, n, m)) return 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            values[j][i] = (*matrix)[i][j];
        }
    }

    free(*matrix);
    *matrix = values;

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
