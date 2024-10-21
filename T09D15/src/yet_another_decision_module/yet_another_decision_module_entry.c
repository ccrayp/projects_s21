#include <stdio.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    double *data;
    int n, flag = 1;
    input(&data, &n, &flag);
    if (flag) {
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
    } else {
        printf("n/a");
    }

    return 0;
}
