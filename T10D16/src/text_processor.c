#include <stdio.h>

#include "s21_string.h"

#define LEN 100

void print_formatted_text(const char *text, int width) {
    int current_length = 0;
    int i = 0;

    while (text[i] != '\0') {
        int word_start = i;
        int word_length = 0;

        while (text[i] != ' ' && text[i] != '\0') {
            word_length++;
            i++;
        }

        if (current_length + word_length > width) {
            if (current_length > 0) {
                putchar('\n');
            }

            if (word_length > width) {
                for (int j = 0; j < width; j++) {
                    putchar(text[word_start + j]);
                }
                putchar('-');
                putchar('\n');
                current_length = 0;
                i++;
                continue;
            }

            current_length = 0;
        }

        if (current_length > 0) {
            putchar(' ');
            current_length++;
        }

        for (int j = 0; j < word_length; j++) {
            putchar(text[word_start + j]);
            current_length++;
        }

        if (text[i] == ' ') {
            i++;
        }
    }

    if (current_length > 0) {
        putchar('\n');
    }
}

int main(int argc, char **argv) {
    int flag = 1;

    if (argc < 1) {
        printf("n/a");
        flag = 0;
    }

    if (!flag && !s21_strcmp(argv[1], "-w")) {
        printf("n/a");
        flag = 0;
    }

    int width = 0;

    if (scanf("%d", &width) != 1) {
        printf("n/a");
        flag = 0;
    }

    if (width < 1) {
        printf("n/a");
        flag = 0;
    }

    int temp = getchar();
    temp++;
    char str[LEN], c = '0';
    int n = 0;

    while (flag && n < LEN - 1 && (c = getchar()) != '\n' && c != EOF) {
        str[n++] = c;
    }
    str[n] = '\0';

    print_formatted_text(str, width);
}
