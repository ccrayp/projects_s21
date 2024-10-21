#include "data_stat.h"

double max(double *data, int n) {
    double *p = data;
    double max_v = *p;
    p++;
    for (; p - data < n; p++) {
        if (*p > max_v) max_v = *p;
    }

    return max_v;
}

double min(double *data, int n) {
    double *p = data;
    double min_v = *p;
    p++;
    for (; p - data < n; p++) {
        if (*p < min_v) min_v = *p;
    }

    return min_v;
}

double mean(double *data, int n) {  //мат ожидание
    double result = 0;
    for (double *p = data; p - data < n; p++) {
        result += (*p);
    }
    return result / n;
}

double variance(double *data, int n) {  //дисперсия
    double sum = 0;

    for (double *p = data; p - data < n; p++) {
        sum += *p;
    }

    double average = sum / n;
    sum = 0;
    for (double *p = data; p - data < n; p++) {
        sum += (*p - average) * (*p - average);
    }

    return sum / n;
}
