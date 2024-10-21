/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int a[NMAX], n = 0;
    if (input(a, &n) == 0) {
        int sum = sum_numbers(a, n);
        int res[NMAX];
        int m = find_numbers(a, n, sum, res);
        if (m != 0) {
            printf("%d\n", sum);
            output(res, m);
        } else {
            printf("n/a");
            return 1;
        }
    } else {
        printf("n/a");
        return 1;
    }
    return 0;
}

int input(int *buffer, int *length) {
    if (scanf("%d", length) == 1) {
        if (*length <= 10 && *length >= 0) {
            for (int i = 0; i < *length; i++) {
                int temp = 0;
                if (scanf("%d", &temp) != 1) {
                    return 1;
                }
                buffer[i] = temp;
            }
            char temp = getchar();
            if (temp != '\n' && temp != EOF) return 1;
        } else
            return 1;
    } else
        return 1;

    return 0;
}

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        printf("%d ", *p);
    }
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer != 0 && buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int m = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0) {
            if (number % buffer[i] == 0) {
                numbers[m] = buffer[i];
                m++;
            }
        }
    }

    return m;
}
