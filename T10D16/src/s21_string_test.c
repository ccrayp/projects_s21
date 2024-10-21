#include "s21_string.h"

#include <stdio.h>

void s21_strlen_test() {
    printf("input: \"%s\"\n", "abcd");
    printf("output: %d\n", s21_strlen("abcd"));
    if (s21_strlen("abcd") != 4)
        printf("FAIL\n\n");
    else
        printf("SUCCESS\n\n");

    printf("input: \"%s\"\n", "");
    printf("output: %d\n", s21_strlen(""));
    if (s21_strlen("") != 0)
        printf("FAIL\n\n");
    else
        printf("SUCCESS\n\n");

    printf("input: \"%s\"\n", "abcdef");
    printf("output: %d\n", s21_strlen("abcdef"));
    if (s21_strlen("abcdef") == 4)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void s21_strcmp_test() {
    printf("input: \"%s\" \"%s\"\n", "ab", "ba");
    printf("output: %d\n", s21_strcmp("ab", "ba"));
    if (s21_strcmp("ab", "ba") != -1)
        printf("FAIL\n\n");
    else
        printf("SUCCESS\n\n");

    printf("input: \"%s\" \"%s\"\n", "ab", "ab");
    printf("output: %d\n", s21_strcmp("ab", "ab"));
    if (s21_strcmp("ab", "ab") != 0)
        printf("FAIL\n\n");
    else
        printf("SUCCESS\n\n");

    printf("input: \"%s\" \"%s\"\n", "", "");
    printf("output: %d\n", s21_strcmp("ab", "ba"));
    if (s21_strcmp("", "\0") != 0)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void s21_strcpy_test() {
    char str1_o[] = "ab", str1[3];
    printf("input: \"%s\"\n", str1_o);
    s21_strcpy(str1, str1_o);
    printf("output: \"%s\"\n", str1);
    if (s21_strcmp(str1_o, str1) != 0)
        printf("FAIL\n\n");
    else
        printf("SUCCESS\n\n");

    char str2_o[] = "", str2[1];
    printf("input: \"%s\"\n", str2_o);
    s21_strcpy(str2, str2_o);
    printf("output: \"%s\"\n", str2);
    s21_strcpy(str2_o, str2);
    if (s21_strcmp(str2_o, str2) != 0)
        printf("FAIL\n\n");
    else
        printf("SUCCESS\n\n");

    char str3_o[] = "abc", str3[4];
    printf("input: \"%s\"\n", str3_o);
    s21_strcpy(str3, str3_o);
    printf("output: \"%s\"\n", str3);
    s21_strcpy(str3_o, str3);
    if (s21_strcmp(str3_o, str3) != 0)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void s21_strcat_test() {
    char str1[20] = "Hello, ";
    char str2[] = "World!";
    printf("input: \"%s\" \"%s\"\n", str1, str2);
    s21_strcat(str1, str2);
    printf("output: \"%s\"\n", str1);
    if (s21_strcmp(str1, "Hello, World!") != 0)
        printf("FAIL\n\n");
    else
        printf("SUCCESS\n\n");

    char str3[20] = "Test";
    char str4[] = "";
    printf("input: \"%s\" \"%s\"\n", str3, str4);
    s21_strcat(str3, str4);
    printf("output: \"%s\"\n", str3);
    if (s21_strcmp(str3, "Test") != 0)
        printf("FAIL\n\n");
    else
        printf("SUCCESS\n\n");

    char str5[20] = "";
    char str6[] = "Hello";
    printf("input: \"%s\" \"%s\"\n", str5, str6);
    s21_strcat(str5, str6);
    printf("output: \"%s\"\n", str5);
    if (s21_strcmp(str5, "Hello") != 0)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void s21_strch_test() {
    char str1[] = "abcd", ch = 'b';
    printf("input: \"%s\" %c\n", str1, ch);
    printf("output: \"%c\"\n", *s21_strch(ch, str1));
    if (*s21_strch(ch, str1) != ch)
        printf("ERROR\n\n");
    else
        printf("SUCCESS\n\n");

    char str2[] = "abcd";
    ch = 'f';
    printf("input: \"%s\" %c\n", str2, ch);
    printf("output: \"%d\"\n", -1);
    if (s21_strch(ch, str2) != 0)
        printf("ERROR\n\n");
    else
        printf("SUCCESS\n\n");

    char str3[] = "abcd";
    ch = '\0';
    printf("input: \"%s\" \\0\n", str3);
    printf("output: \\0\n");
    if (*s21_strch(ch, str3) != ch)
        printf("ERROR\n");
    else
        printf("SUCCESS\n");
}

void s21_strstr_test() {
    char haystack1[] = "Hello, World!";
    char needle1[] = "World";
    printf("input: \"%s\" \"%s\"\n", haystack1, needle1);
    char *result1 = s21_strstr(haystack1, needle1);
    printf("output: \"%s\"\n", result1);
    if (result1 == 0 && s21_strcmp(result1, "World!") != 0)
        printf("FAIL\n\n");
    else
        printf("SUCCESS\n\n");

    char needle2[] = "Earth";
    printf("input: \"%s\" \"%s\"\n", haystack1, needle2);
    char *result2 = s21_strstr(haystack1, needle2);
    printf("output: \"%s\"\n", result2);
    if (result2 != 0)
        printf("FAIL\n\n");
    else
        printf("SUCCESS\n\n");

    char *needle3 = "";
    printf("input: \"%s\" \"%s\"\n", haystack1, needle3);
    char *result3 = s21_strstr(haystack1, needle3);
    printf("output: \"%s\"\n", result1);
    if (result3 == NULL && s21_strcmp(result3, haystack1) != 0)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

void s21_strtok_test() {
    char str1[] = "Hello, World! This is a test.";
    const char *delim1 = " ,.!";
    printf("input: \"%s\" \"%s\"\n", str1, delim1);
    char *token1 = s21_strtok(str1, delim1);
    printf("output: \"%s\"\n", token1);
    if (s21_strcmp(token1, "Hello") == 0)
        printf("FAIL\n\n");
    else
        printf("SUCCESS\n\n");

    char str2[] = " ,.! ";
    printf("input: \"%s\" \"%s\"\n", str2, delim1);
    char *token2 = s21_strtok(str2, delim1);
    printf("output: \"%s\"\n", token2);
    if (token2 != 0)
        printf("FAIL\n\n");
    else
        printf("SUCCESS\n\n");

    char str3[] = "";
    printf("input: \"%s\" \"%s\"\n", str3, delim1);
    char *token3 = s21_strtok(str3, delim1);
    printf("output: \"%s\"\n", token3);
    if (token3 != 0)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");
}

int main() {
#ifdef Q1
    printf("*************Testing s21_strlen*************\n");
    s21_strlen_test();
#endif
#ifdef Q2
    printf("*************Testing s21_strcmp*************\n");
    s21_strcmp_test();
#endif
#ifdef Q3
    printf("*************Testing s21_strcpy*************\n");
    s21_strcpy_test();
#endif
#ifdef Q4
    printf("*************Testing s21_strcat*************\n");
    s21_strcat_test();
#endif
#ifdef Q5
    printf("*************Testing s21_strch*************\n");
    s21_strch_test();
#endif
#ifdef Q6
    printf("*************Testing s21_strstr*************\n");
    s21_strstr_test();
#endif
#ifdef Q7
    printf("*************Testing s21_strtok*************\n");
    s21_strtok_test();
#endif
    return 0;
}
