#include "sort.h"

int partition(double *data, int low, int high) {
    double pivot = data[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (data[j] <= pivot) {
            i++;
            swap(&data[i], &data[j]);
        }
    }
    swap(&data[i + 1], &data[high]);
    return (i + 1);
}

void sort(double *data, int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);
        sort(data, low, pi - 1);
        sort(data, pi + 1, high);
    }
}

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}
