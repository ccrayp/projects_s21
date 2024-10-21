#include <math.h>
#include <stdio.h>

int long_prime(int val);
int is_prime(int val);
int div(int val, int d);

int main() {
    int val = 0;
    int res = scanf("%d", &val);

    if (res != 1) {
        printf("Error!");
        return 1;
    }

    char temp;
    temp = getchar();
    if (temp != '\n' && temp != EOF) {
        printf("Error!");
        return 1;
    }

    if (val < 0) val = val*(-1);

    if (val == 1)
        printf("n/a");
    else if (val == 0)
        printf("n/a");

    printf("%d", long_prime(val));
    return 0;
}

int is_prime(int val) {
    if (val <= 1) return 0;
    for (int d = 2; d * d <= val; d++) {
        if (div(val, d) > 0 && div(val, d) * d == val) {
            return 0;
        }
    }
    return 1;
}

int long_prime(int val) {
    int l = 1;
    for (int d = 2; d <= val; d++) {
        if (div(val, d) > 0 && div(val, d) * d == val && is_prime(d)) {
            l = d;
        }
    }
    return l;
}

int div(int val, int d) {
    int count = 0;
    while (val >= d) {
        val -= d;
        count++;
    }

    return count;
}
