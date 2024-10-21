#include <math.h>
#include <stdio.h>

void decode();
void encode();
int get_hnum();
void clear_screen();

int main(int argc, char **argv) {
    if (argc == 2) {
        if (*argv[1] == '0')
            encode();
        else if (*argv[1] == '1')
            decode();
    }
    return 0;
}

int get() {
    char c1, c2;

    c1 = (char)getchar();
    c2 = (char)getchar();
    if (('0' <= c1) && (c1 <= '9')) {
        c1 -= '0';
    } else if (('A' <= c1) && (c1 <= 'F')) {
        c1 -= 'A';
        c1 += 10;
    } else {
        return 256;
    }

    if (('0' <= c2) && (c2 <= '9')) {
        c2 -= '0';
    } else if (('A' <= c2) && (c2 <= 'F')) {
        c2 -= 'A';
        c2 += 10;
    } else {
        return 256;
    }

    return (16 * c1 + c2);
}

void decode() {
    char tc;
    int a;

    while (1) {
        a = get();
        if (a == 256) {
            clear_screen();
            printf("n/a");
            return;
        }

        printf("%c ", (char)a);

        tc = getchar();
        if (tc != ' ') {
            if (tc != EOF && tc != '\n') {
                clear_screen();
                printf("n/a");
                return;
            }
            if (tc == EOF || tc == '\n') {
                return;
            }
        }
    }
}

void encode() {
    char c = getchar();
    while (c != EOF && c != '\n') {
        char tc = c;

        c = getchar();
        if (c != EOF && c != '\n' && c != ' ') {
            printf("n/a\n");
            return;
        }

        printf("%hhX ", tc);

        if (c == ' ') c = getchar();
    }
}

void clear_screen() { printf("\033[H\033[J"); }
