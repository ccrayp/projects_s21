#include <stdio.h>
#include <stdlib.h>

int input(int *mode, int *M, int *N);
void method_1(const int M, const int N);
void method_2(const int M, const int N);
void method_3(const int M, const int N);
void method_4(const int M, const int N);
void output_matrix(const int M, const int N, int **m);
void output_matrix_static(const int M, const int N, int m[M][N]);

int main() {
    int mode, M, N;
    if (input(&mode, &M, &N) == 0) {
        switch (mode) {
            case 1:
                method_1(M, N);
                break;
            case 2:
                method_2(M, N);
                break;
            case 3:
                method_3(M, N);
                break;
            case 4:
                method_4(M, N);
                break;
        }
        return 0;
    }
    printf("n/a");
    return 1;
}

int input(int *mode, int *M, int *N) {
    if (scanf("%d", mode) != 1) return 1;
    if (!(*mode > 0 && *mode < 5)) return 1;

    if (scanf("%d", M) != 1) return 1;
    if (*M <= 0) return 1;
    if (*mode == 1 && *M > 100) return 1;

    if (scanf("%d", N) != 1) return 1;
    if (*N <= 0) return 1;
    if (*mode == 1 && *N > 100) return 1;

    int temp = getchar();
    if (temp != '\n' && temp != EOF) return 1;

    return 0;
}

void output_matrix(const int M, const int N, int **m) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (j != N - 1)
                printf("%d ", m[i][j]);
            else
                printf("%d", m[i][j]);
        }
        if (i != M - 1) printf("\n");
    }
}

void output_matrix_static(const int M, const int N, int m[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            if (j != N - 1)
                printf("%d ", m[i][j]);
            else
                printf("%d", m[i][j]);
        if (i != M - 1) printf("\n");
    }
}

void method_1(const int M, const int N) {
    int flag = 0;
    int m[M][N];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &m[i][j]) != 1) {
                flag = 1;
                break;
            }
            if (flag) {
                printf("n/a");
                break;
            }
        }
    if (!flag) {
        output_matrix_static(M, N, m);
    }
}

void method_2(const int M, const int N) {
    int **single_array_matrix = malloc(M * N * sizeof(int) + M * sizeof(int *));
    int *ptr = (int *)(single_array_matrix + M);
    int flag = 0;
    for (int i = 0; i < M; i++) single_array_matrix[i] = ptr + N * i;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            int temp = 0;
            if (scanf("%d", &temp) != 1) {
                flag = 1;
                break;
            }
            single_array_matrix[i][j] = temp;
            if (flag) {
                printf("n/a");
                break;
            }
        }

    output_matrix(M, N, single_array_matrix);

    free(single_array_matrix);
}

void method_3(const int M, const int N) {
    int flag = 0;
    int **pointer_array = malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) pointer_array[i] = malloc(N * sizeof(int));

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            int temp = 0;
            if (scanf("%d", &temp) != 1) {
                flag = 1;
                break;
            }
            pointer_array[i][j] = temp;
            if (flag) {
                printf("n/a");
                break;
            }
        }

    output_matrix(M, N, pointer_array);

    for (int i = 0; i < M; i++) free(pointer_array[i]);
    free(pointer_array);
}

void method_4(const int M, const int N) {
    int **pointer_array = malloc(M * sizeof(int *));
    int *values_array = malloc(M * N * sizeof(int));
    int flag = 0;

    for (int i = 0; i < M; i++) pointer_array[i] = values_array + N * i;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            int temp = 0;
            if (scanf("%d", &temp) != 1) {
                flag = 1;
                break;
            }
            pointer_array[i][j] = temp;
            if (flag) {
                printf("n/a");
                break;
            }
        }

    output_matrix(M, N, pointer_array);

    free(values_array);
    free(pointer_array);
}
