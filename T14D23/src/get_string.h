#ifndef GET_STRING_H
#define GET_STRING_H

#include <stdlib.h>

#define RESIZE_BUFFER_FACTOR 2
#define INITIAL_SIZE 10

char *read_line() {
    size_t size = INITIAL_SIZE;
    char *buffer = malloc(size);
    if (!buffer) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return NULL;
    }

    size_t length = 0;
    int ch;

    while (1) {
        ch = getchar();

        if (ch == '\n' || ch == EOF) {
            break;
        }

        if (length + 1 >= size) {
            size *= 2;
            char *new_buffer = realloc(buffer, size);
            if (!new_buffer) {
                free(buffer);
                fprintf(stderr, "Ошибка выделения памяти\n");
                return NULL;
            }
            buffer = new_buffer;
        }

        buffer[length++] = ch;
    }

    buffer[length] = '\0';
    return buffer;
}

char *input_filepath() {
    char *filepath = read_line();
    char *temp = (char *)malloc(sizeof(filepath) + 4);
    strcpy(temp, "../");
    strcat(temp, filepath);
    free(filepath);
    return temp;
}

#endif
