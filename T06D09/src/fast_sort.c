#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void copy(const int *a, int *b);
int partition(int *a, int low, int high);
void sort1(int *a, int low, int high);
void heapify(int *a, int n, int i);
void sort2(int *a, int n);

int main() {
    int a[NMAX], b[NMAX];
    if (input(a) == 1) {
        printf("n/a");
        return 1;
    }
    copy(a, b);
    sort1(a, 0, NMAX);
    output(a);
    printf("\n");
    sort2(b, NMAX);
    output(b);
    return 0;
}

int input(int *a) {
    for (int *p = a; p - a < NMAX; p++) {
        if (scanf("%d", p) != 1) return 1;
    }

    int temp = getchar();
    if (temp != '\n' && temp != EOF) return 1;

    return 0;
}

void output(int *a) {
    for (int i = 0; i < NMAX; i++) printf("%d ", a[i]);
}

void copy(const int *a, int *b) {
    for (int i = 0; i < NMAX; i++) b[i] = a[i];
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a, int low, int high) {
    int pivot = a[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void sort1(int *a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        sort1(a, low, pi - 1);
        sort1(a, pi + 1, high);
    }
}

void heapify(int *a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) largest = left;

    if (right < n && a[right] > a[largest]) largest = right;

    if (largest != i) {
        swap(&a[i], &a[largest]);

        heapify(a, n, largest);
    }
}

void sort2(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}
