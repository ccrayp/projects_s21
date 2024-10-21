#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdlib.h>

int s21_strlen(const char *string);
int s21_strcmp(const char *string_1, const char *string_2);
char *s21_strcpy(char destination[], const char source[]);
char *s21_strcat(char *string_1, const char *string_2);
char *s21_strch(const char ch, char *string);
char *s21_strchr(const char ch, char *string);
char *s21_strstr(const char *string_1, const char *string_2);
char *s21_strtok(char *string, const char *delim);

#endif
