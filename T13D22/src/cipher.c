#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logger.h"

#define START_LENGTH_LINE 32
#define RESIZE_BUFFER_FACTOR 2

void menu(int mode, char *filepath);
void print_file(char *filepath);
void add_to_end_file(char *filepath);
void encrypt(char *filepath);
char *get_string();
int is_empty(char *filepath);
int is_exist(char *filepath);

int main() {
    int mode = 0, flag = 1;
    char *filepath;
    while (mode != -1) {
        flag = 1;
        if (scanf("%d", &mode) != 1)
            flag = 0;
        getchar();

        if (((mode <= 0) && (mode != -1)) || (mode > 4))
            flag = 0;

        if (flag) {
            if (mode == 1)
                filepath = get_string();
            if ((filepath != NULL) && (strlen(filepath) != 0))
            {
                if (mode != -1) menu(mode, filepath);
            }
        } else {
            printf("n/a\n");
        }
    }

    if (filepath)
        free(filepath);

    return 0;
}

char *get_string() {
    char c, *temp_str;
    char *str = (char *)malloc(START_LENGTH_LINE * sizeof(char));
    int size = 0;
    int real_size = START_LENGTH_LINE;

    while (((c = getchar()) != (int)'\n') && (c != (int)EOF)) {
        if (size + 1 > real_size) {
            temp_str = (char *)realloc(str, real_size * RESIZE_BUFFER_FACTOR * sizeof(char));
            if (temp_str) str = temp_str;
            real_size *= RESIZE_BUFFER_FACTOR;
        }

        str[size++] = c;
    }

    if (size + 1 > real_size) {
        temp_str = (char *)realloc(str, (real_size + 1) * sizeof(char));
        if (temp_str) str = temp_str;
    }

    str[size] = '\0';

    return str;
}

void menu(int mode, char *filepath) {
    if (is_exist(filepath)) {
        switch (mode) {
            case -1:
                break;
            case 1:
                print_file(filepath);
                break;
            case 2:
                add_to_end_file(filepath);
                break;
            case 3:
                encrypt(filepath);
                break;
            case 4:
                // print_file(mode);
                break;
        }
    } else {
        char message[256];
        snprintf(message, sizeof(message), "Файл не был \"%s\" открыт", filepath);
        cat_log(ERROR, message);
        printf("n/a\n");
    }
}

void print_file(char *filepath) {
    if (is_exist(filepath) && !is_empty(filepath)) {
        char ch;
        FILE *in = fopen(filepath, "r");
        char message[256];
        snprintf(message, sizeof(message), "Файл \"%s\" открыт", filepath);
        cat_log(INFO, message);
        while ((ch = fgetc(in)) != EOF)
            putchar(ch);
        char message2[256];
        snprintf(message2, sizeof(message2), "Файл \"%s\" закрыт", filepath);
        cat_log(INFO, message2);
        fclose(in);
    } else {

        printf("n/a\n");
    }
}

int is_empty(char *filepath) {
    FILE *in = fopen(filepath, "r");
    if (in == NULL) {
        char message[256];
        snprintf(message, sizeof(message), "Файл \"%s\" пуст", filepath);
        cat_log(WARNING, message);
        return 1;
    }
    int result = (fgetc(in) == EOF);
    if(fgetc(in) == EOF) {
        result = 1;
    } else {
        result =  0;
    }
    fclose(in);
    return result;
}

int is_exist(char *filepath)
{
    FILE *in = fopen(filepath, "r");
    char message[256];
    snprintf(message, sizeof(message), "Файл \"%s\" открыт", filepath);
    cat_log(INFO, message);
    if (in) {
        fclose(in);
        char message[256];
        snprintf(message, sizeof(message), "Файл \"%s\" закрыт", filepath);
        cat_log(INFO, message);
    }
    if(in) {
        return 1;
    } else {
        return 0;
    }

}

void add_to_end_file(char *filepath) {
    char *string = get_string();
    strcat(string, "\n");
    FILE *out;
    int res = is_empty(filepath);
    if (res == 1) {
        out = fopen(filepath, "w");
        char message[256];
        snprintf(message, sizeof(message), "Файл \"%s\" открыт", filepath);
        cat_log(INFO, message);
    } else {
        out = fopen(filepath, "a");
        char message[256];
        snprintf(message, sizeof(message), "Файл \"%s\" открыт", filepath);
        cat_log(INFO, message);
    }
    if (out != 0 && strlen(string) != 0) {
        char message[256];
        snprintf(message, sizeof(message), "В файл \"%s\" было добавленно сообщение %s", filepath, string);
        cat_log(INFO, message);
        fputs(string, out);
    }

    fclose(out);
    char message[256];
    snprintf(message, sizeof(message), "Файл \"%s\" закрыт", filepath);
    cat_log(INFO, message);
    free(string);
    print_file(filepath);
}

void encrypt(char *filepath) {

    printf("%s", filepath);


}
