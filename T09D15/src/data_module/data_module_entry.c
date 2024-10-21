#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "data_process.h"

int main() {
    double *data = NULL;
    int n = 0, flag = 1;

    // Don`t forget to allocate memory !

    input(&data, &n, &flag);

    if (flag) {
        if (normalization(data, n)) output(data, n);
        free(data);
    } else
        printf("ERROR");

    return 0;
}
