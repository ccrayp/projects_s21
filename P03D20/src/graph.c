#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "get_data.h"
#include "list.h"
#include "polish_notation.h"
#include "stack.h"

#define HEIGHT 25
#define WIDTH 80

#define M_PI 3.14159265358979323846

void drawGraph(List *list) {
    char graph[HEIGHT][WIDTH + 1];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            graph[i][j] = '.';
        }
        graph[i][WIDTH] = '\0';
    }

    for (int x = 0; x < WIDTH; x++) {
        double xVal = (double)x * (4 * M_PI) / (WIDTH - 1);
        double y = solve(list, xVal);

        int yPos = round(HEIGHT / 2 + (y * (HEIGHT / 2)));
        if (yPos >= 0 && yPos < HEIGHT) {
            graph[yPos][x] = '*';
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        printf("%s\n", graph[i]);
    }
}

int main() {
    printf("Enter function: ");
    char *string_1 = get_string();

    List *list = string_to_list(string_1);
    free(string_1);
    List *result = RPN(list);
    drawGraph(result);
    list_destroy(list);
    list_destroy(result);

    return 0;
}