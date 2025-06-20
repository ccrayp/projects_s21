#include "data_process.h"

#include <stdio.h>
int normalization(double *data, int n) {
    int result = 1;
    double max_value = max(data, n);
    double min_value = min(data, n);
    double size = max_value - min_value;

    if (fabs(size) > EPS) {
        for (int i = 0; i < n; i++) {
            data[i] = (data[i] - min_value) / size;
        }
    } else {
        result = 0;
    }

    return result;
}
