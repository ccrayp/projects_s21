#include <stdio.h>
#include <stdlib.h>

int input(int *M, int *N);
int **input_matrix(const int M, const int N);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second,
           int n_second, int m_second, int ***matrix_result, int n_result, int m_result);
int transpose(int ***matrix, int n, int m);
void output_matrix(const int M, const int N, int **m);
int create_matrix(int ***matrix, int rows, int cols);
int mult(int **matrix_first, int n_first, int m_first,
             int **matrix_second, int n_second, int m_second,
             int ***matrix_result, int n_result, int m_result);

int main() {
    int mode = 0, M2 = 0, M1 = 0, N2 = 0, N1 = 0, **res = NULL, **m1 = NULL, **m2 = NULL; //flag = 1;
    if (scanf("%d", &mode) != 1) {
        printf("n/a");
        return 1;
    }
    if (input(&M1, &N1) != 0) return 1;
    m1 = input_matrix(M1, N1);
    if (m1 == NULL) {
        printf("n/a");
        //flag = 0;
    }
    if (mode != 3) {
        if (input(&M2, &N2) != 0) return 1;
        m2 = input_matrix(M2, N2);
        if (m2 == NULL) {
            printf("n/a");
            //flag = 0;
        }
    }
    switch (mode) {
        case 1:
            if (sum(m1, M1, N1, m2, M2, N2, &res, M2, N2) == 1) {
                printf("n/a");
                //flag = 0;
            }
            output_matrix(M2, N2, res);
            break;
            case 2:
            if (mult(m1, M1, N1, m2, M2, N2, &res, M1, N2) != 0) {
                printf("n/a");
            }
            output_matrix(M1, N2, res);
            break;
        case 3:
            if (transpose(&m1, M1, N1) != 0) {
                printf("n/a");
               // flag = 0;
            }
            output_matrix(N1, M1, m1);
            break;
    }
    /*if (flag && res != NULL) {
        if(mode == 1)
            for (int i = 0; i < M2; i++) free(res[i]);
        else if(mode == 2)
            for (int i = 0; i < M1; i++) free(res[i]);
        free(res);
    }
    if(m1 != NULL) free(m1);
    if(m2 != NULL) free(m2);*/
    return 0;
}

int input(int *M, int *N) {
    if (scanf("%d", M) != 1) return 1;
    if (*M <= 0) return 1;

    if (scanf("%d", N) != 1) return 1;
    if (*N <= 0) return 1;

    int temp = getchar();
    if (temp != '\n' && temp != EOF) return 1;

    return 0;
}

int create_matrix(int ***mptr, const int m, const int n) {
    int **values = malloc(n * m * sizeof(int) + m * sizeof(int *));
    if (!values) return 1;
    int *ptr = (int *)(values + m);
    for (int i = 0; i < m; i++) values[i] = ptr + i * n;
    *mptr = values;

    return 0;
}

int **input_matrix(const int M, const int N) {
    int **single_array_matrix = malloc(M * N * sizeof(int) + M * sizeof(int *));
    int *ptr = (int *)(single_array_matrix + M);
    int flag = 0;
    for (int i = 0; i < M; i++) single_array_matrix[i] = ptr + N * i;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            int temp = 0;
            if (scanf("%d", &temp) != 1) {
                flag = 1;
                return NULL;
            }
            single_array_matrix[i][j] = temp;
            if (flag) {
                printf("n/a");
                return NULL;
            }
        }

    return single_array_matrix;
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

int sum(int **matrix_first, int n_first, int m_first, int **matrix_second,
            int n_second, int m_second, int ***matrix_result, int n_result, int m_result)
{
    if ((n_first != n_second) || (m_first != m_second) || (n_first != n_result) || (m_first != m_result)) return 1;

    create_matrix(matrix_result, n_second, m_second);

    for (int i = 0; i < n_first; i++) {
        for (int j = 0; j < m_first; j++) {
            (*matrix_result)[i][j] = matrix_first[i][j] + matrix_second[i][j];
        }
    }

    return 0;
}


int mult(int **matrix_first, int n_first, int m_first,
             int **matrix_second, int n_second, int m_second,
             int ***matrix_result, int n_result, int m_result) {

    if (m_first != n_second || n_first != n_result || m_second != m_result) {
        return 1;
    }

    if (create_matrix(matrix_result, n_first, m_second) != 0) {
        return 1;
    }

    for (int i = 0; i < n_first; i++) {
        for (int j = 0; j < m_second; j++) {
            (*matrix_result)[i][j] = 0;
            for (int k = 0; k < m_first; k++) {
                (*matrix_result)[i][j] += matrix_first[i][k] * matrix_second[k][j];
            }
        }
    }

    return 0;
}

int transpose(int ***matrix, int m, int n)
{
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
