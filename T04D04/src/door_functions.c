#include <math.h>
#include <stdio.h>

double func1();
double func2();
double func3();

int main() {
    double pi = M_PI;
    double t = (2 * pi) / 41;
    for (double a = pi * (-1); a < pi; a += t) {
        printf("%.7f | ", a);

        double res = func1(a);
        if (a != -1)
            printf("%.7f | ", res);
        else
            printf(" - | ");

        res = func2(a);
        if (res != -1)
            printf("%.7f | ", res);
        else
            printf("- | ");

        res = func3(a);
        if (a != -1)
            printf("%.7f\n", res);
        else
            printf(" - \n");
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
