#include <stdio.h>

#define LEN 100
#define max(a, b) (((a) > (b)) ? (a) : (b))

int input(int *a);
void output(int *a, int n);
void sum(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, const int *buff2, int *result, int *result_length);
void swap(int *a, int *b);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int buff1[LEN + 1], buff2[LEN + 1], result_sum[LEN + 1], result_sub[LEN + 1];
    int len1, len2, len3, len4;

    for (int i = 0; i <= LEN; i++) {
        buff1[i] = 0;
        buff2[i] = 0;
        result_sum[i] = 0;
        result_sub[i] = 0;
    }

    if ((len1 = input(buff1)) < 0) {
        printf("n/a");
        return 1;
    }
    if ((len2 = input(buff2)) < 0) {
        printf("n/a");
        return 1;
    }

    sum(buff1, len1, buff2, len2, result_sum, &len3);
    sub(buff1, len1, buff2, result_sub, &len4);

    if (result_sub[LEN] >= 5) {
        printf("n/a");
        return 1;
    }

    output(result_sum, len3);
    printf("\n");
    output(result_sub, len4);

    return 0;
}

int input(int *a) {
    int i = 0;

    int temp = getchar();
    while (1) {
        if (i == LEN) return -1;
        if (('0' <= temp) && (temp <= '9'))
            a[i++] = temp - '0';
        else
            return -1;

        temp = getchar();
        if (temp == ' ') {
            temp = getchar();
        } else {
            if ((temp != '\n') && (temp != EOF))
                return -1;
            else
                break;
        }
    }

    int *start, *end;
    start = a;
    end = start + i - 1;
    while (start < end) swap(start++, end--);

    return i;
}

void output(int *a, int n) {
    for (int i = n; i > 0; i--) {
        if (i != n)
            printf(" %d", a[i - 1]);
        else
            printf("%d", a[i - 1]);
    }
}

void swap(int *a, int *b) {
    if (*a == *b) return;
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sum(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length) {
    int carry = 0;
    *result_length = max(max(len1, len2), LEN);
    for (int i = 0; i <= LEN; i++) {
        int carry2 = (buff1[i] + buff2[i] + carry) / 10;
        result[i] = (buff1[i] + buff2[i] + carry) % 10;
        carry = carry2;
    }

    while (*result_length && !result[*result_length]) (*result_length)--;
    (*result_length)++;
}

void sub(int *buff1, int len1, const int *buff2, int *result, int *result_length) {
    int indx = 0;
    for (int i = 0; i <= LEN; i++) result[i] = (9 - buff2[i]);
    do {
        result[indx] = (result[indx] + 1) % 10;
    } while ((++indx <= LEN) && !result[indx - 1]);

    sum(result, LEN + 1, buff1, len1, result, result_length);
}
