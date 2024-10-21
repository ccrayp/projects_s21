#include "s21_string.h"

#include <stdio.h>

int s21_strlen(const char *string) {
    int counter = 0;
    for (int i = 0; string[i] != '\0'; i++) counter++;
    return counter;
}

int s21_strcmp(const char *string_1, const char *string_2) {
    if (s21_strlen(string_1) == 0 && s21_strlen(string_2) == 0)
        return *(unsigned char *)string_1 - *(unsigned char *)string_2;

    while (*string_1 && (*string_1 == *string_2)) {
        string_1++;
        string_2++;
    }

    return *(unsigned char *)string_1 - *(unsigned char *)string_2;
}

char *s21_strcpy(char destination[], const char source[]) {
    if (source != NULL) {
        for (int i = 0; (destination[i] = source[i]) != '\0'; i++) {
        }
    }
    return destination;
}

char *s21_strcat(char *string_1, const char *string_2) {
    char *ptr = string_1 + s21_strlen(string_1);
    while ((*ptr++ = *string_2++))
        ;

    return string_1;
}

char *s21_strch(const char ch, char *string) {
    char *p;
    for (p = string; *p != '\0'; p++) {
        if (*p == ch) return p;
    }
    if (ch == '\0') return p;

    return 0;
}

char *s21_strchr(const char ch, char *string) {
    char *p, *res = 0;
    for (p = string; *p != '\0'; p++) {
        if (*p == ch) res = p;
    }
    if (ch == '\0') return p;

    return res;
}

char *s21_strstr(const char *string_1, const char *string_2) {
    if (*string_2 == '\0') {
        return (char *)string_1;
    }

    for (const char *p = string_1; *p != '\0'; p++) {
        const char *h = p;
        const char *n = string_2;

        while (*h != '\0' && *n != '\0' && *h == *n) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char *)p;
        }
    }

    return 0;
}

char *s21_strtok(char *string, const char *delim) {
    char *last = 0;
    if (string == NULL) {
        string = last;
    }

    while (*string && s21_strchr(*delim, string)) {
        string++;
    }

    if (*string == '\0') {
        last = 0;
        return 0;
    }

    char *token_start = string;

    while (*string && !s21_strchr(*delim, string)) {
        string++;
    }

    if (*string) {
        *string = '\0';
        last = string + 1;
    } else {
        last = 0;
    }

    return token_start;
}
