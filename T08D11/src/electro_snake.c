#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

void sort_matrix(int **matrix, int rows, int cols) {
    int *temp = (int *)malloc(rows * cols * sizeof(int));
    int index = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[index++] = matrix[i][j];
        }
    }

    qsort(temp, rows * cols, sizeof(int), compare);

    index = 0;
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = temp[index++];
            }
        } else {
            for (int j = cols - 1; j >= 0; j--) {
                matrix[i][j] = temp[index++];
            }
        }
    }

    free(temp);
}

void sort_matrix_vertical_snake(int **matrix, int rows, int cols) {
    int *temp = (int *)malloc(rows * cols * sizeof(int));
    int index = 0;

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            temp[index++] = matrix[i][j];
        }
    }

    qsort(temp, rows * cols, sizeof(int), compare);

    index = 0;
    for (int j = 0; j < cols; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < rows; i++) {
                matrix[i][j] = temp[index++];
            }
        } else {
            for (int i = rows - 1; i >= 0; i--) {
                matrix[i][j] = temp[index++];
            }
        }
    }

    free(temp);
}

void sort_matrix_snake(int **matrix, int rows, int cols) {
    sort_matrix_vertical_snake(matrix, rows, cols);
    print_matrix(matrix, rows, cols);
    printf("\n");

    sort_matrix(matrix, rows, cols);
    print_matrix(matrix, rows, cols);
}

int main() {
    int rows, cols;

    while (scanf("%d %d", &rows, &cols) == 2) {
        if (rows == 0 && cols == 0) {
            printf("n/a\n");
            continue;
        }

        int **matrix = (int **)malloc(rows * sizeof(int *));
        for (int i = 0; i < rows; i++) {
            matrix[i] = (int *)malloc(cols * sizeof(int));
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        sort_matrix_snake(matrix, rows, cols);

        for (int i = 0; i < rows; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }

    return 0;
}
