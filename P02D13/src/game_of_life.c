#include <stdio.h>
#include <time.h>

#define R 25
#define C 80
#define ALS '@'

void draw_field(char fiend[R][C]);
void init_field(char field[R][C], int *flag);
void start(int *flag, int *speed, int argc, char **argv);
void apply_rules(char field[R][C]);
void copy(char field_1[R][C], char field_2[R][C]);
int count_alive(char field[R][C], int x, int y);
void sleep(int milliseconds);

int main(int argc, char **argv) {
    int flag = 1, speed = 0;
    char field[R][C] = {0};
    start(&flag, &speed, argc, argv);
    if (flag) {
        init_field(field, &flag);
    }

    if (flag) {
        speed = 1e3 / speed;
        printf("\033[2J\033[1;1H");
        draw_field(field);
        sleep(speed);
        while (1) {
            printf("\033[2J\033[1;1H");
            apply_rules(field);
            draw_field(field);
            sleep(speed);
        }
    }
    return 0;
}

void sleep(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds * (CLOCKS_PER_SEC / 1000))
        ;
}

void start(int *flag, int *speed, int argc, char **argv) {
    if (argc == 1) {
        *flag = 0;
        printf("n/a");
    }

    char *data = argv[1];
    if (*flag) {
        while ('0' <= *data && *data <= '9') {
            *speed *= 10;
            *speed += *data - '0';
            data += 1;
        }
    }

    if ((*speed < 1 || *speed > 100) && *flag) {
        *flag = 0;
        printf("n/a");
    }
}

void draw_field(char field[R][C]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c", field[i][j]);
        }
        printf("\n");
    }
}

void init_field(char field[R][C], int *flag) {
    char c;
    for (int i = 0; i < R && flag; i++) {
        for (int j = 0; j < C && flag; j++) {
            if (scanf("%c", &c) != 1) {
                flag = 0;
                printf("n/a");
            } else if (c == '.') {
                field[i][j] = ' ';
            } else if (c == '@') {
                field[i][j] = '@';
            }
        }
    }
}

void copy(char field_1[R][C], char field_2[R][C]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            field_2[i][j] = field_1[i][j];
        }
    }
}

int count_alive(char field[R][C], int x, int y) {
    int counter = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((field[(R + x + i) % R][(C + y + j) % C] == '@') && !(i == 0 && j == 0)) counter++;
        }
    }
    return counter;
}

void apply_rules(char field[R][C]) {
    char temp[R][C];
    copy(field, temp);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int quantity = count_alive(temp, i, j);
            if ((field[i][j] == ALS && quantity == 2) || (quantity == 3))
                field[i][j] = ALS;
            else
                field[i][j] = ' ';
        }
    }
}