#include <stdio.h>

#include "../data_libs/sort.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

//#define USE_MACRO_IO
#ifdef USE_MACRO_IO
#define input(data, n, flag) INPUT(double, lf, data, n, flag)
#define output(data, n) OUTPUT(lf, data, n)
#include "../data_libs/data_io_macro.h"
#else
#include "../data_libs/data_io.h"
#endif

int main() {
    double *data;
    int n, flag = 1;

    printf("LOAD DATA...\n");
    input(&data, &n, &flag);

    if (flag) {
        printf("RAW DATA:\n\t");
        output(data, n);

        printf("\nNORMALIZED DATA:\n\t");
        normalization(data, n);
        output(data, n);

        printf("\nSORTED NORMALIZED DATA:\n\t");
        sort(data, 0, n);
        output(data, n);

        printf("\nFINAL DECISION:\n\t");
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
    }

    return 0;
}
