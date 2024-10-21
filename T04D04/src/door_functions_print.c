#include <math.h>
#include <stdio.h>

double func1(double x);
double func2(double x);
double func3(double x);

double func_by_number(double x, int n) {
    if (n == 1) return func1(x);
    if (n == 2) return func2(x);
    if (n == 3) return func3(x);
}

double scale(int n) {
    if (n == 1) return 21.0 / 1;
    if (n == 2) return 21.0 / 0.5;
    if (n == 3) return 21.0 / 180;
}

int main() {
    const double step = (2 * M_PI) / 41;
    int curr_y = 21;
    double x;
    int y;

    for (int n = 1; n < 4; n++) {
        printf("\n******************************************\n");
        x = M_PI * (-1);
        curr_y = 21;

        while (curr_y) {
            x = M_PI * (-1);
            while (x <= M_PI) {
                y = -1;
                if (func_by_number(x, n) != -1) y = round(func_by_number(x, n) * scale(n));

                if (y == curr_y)
                    printf("*");
                else
                    printf(" ");
                x += step;
            }

            printf("\n");
            curr_y--;
        }

        printf("\n******************************************\n");
    }

    return 0;
}

double func1(double x) { return (double)1 / (1 + pow(x, 2)); }

double func2(double x) {
    double t1 = sqrt(1 + 4 * x * x);
    double t2 = t1 - pow(x, 2) - 1;
    if (t2 >= 0) return sqrt(t2);
    return -1;
}

double func3(double x) {
    if (x != 0) return 1 / pow(x, 2);
    return -1;
}
