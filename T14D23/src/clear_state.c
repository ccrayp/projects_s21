#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary.h"
#include "data.h"
#include "get_string.h"

int check_date(Data etalon);
int is_date_in_range(Data record, Data start, Data end);
void clear_state(const char *filepath, Data start_date, Data end_date);

int main() {
    int exit = -100;
    char *filepath = NULL;

    while (exit != -1) {
        if (exit != -100)
            while (getchar() != '\n')
                ;
        exit = 1;

        printf("Enter file path: ");
        filepath = input_filepath();
        if (strcmp(filepath, "../-1") == 0)
            exit = -1;
        else {
            Data start_date, end_date;
            scanf("%d.%d.%d %d.%d.%d", &start_date.day, &start_date.month, &start_date.year, &end_date.day,
                  &end_date.month, &end_date.year);

            start_date.hour = 0;
            start_date.minute = 0;
            start_date.seconds = 0;

            end_date.hour = 23;
            end_date.minute = 59;
            end_date.seconds = 59;

            clear_state(filepath, start_date, end_date);
        }
    }
    free(filepath);
    return 0;
}

int check_date(Data etalon) {
    int result = 1;
    if (!(etalon.day >= 0 && etalon.day <= 31)) result = 0;
    if (!(etalon.month >= 0 && etalon.month <= 12)) result = 0;
    if (!(etalon.year >= 0 && etalon.year <= 9999)) result = 0;

    return result;
}

int is_date_in_range(Data record, Data start, Data end) {
    if (record.year < start.year || record.year > end.year) {
        return 0;
    }
    if (record.year == start.year &&
        (record.month < start.month || (record.month == start.month && record.day < start.day))) {
        return 0;
    }
    if (record.year == end.year &&
        (record.month > end.month || (record.month == end.month && record.day > end.day))) {
        return 0;
    }
    return 1;
}

void clear_state(const char *filepath, Data start_date, Data end_date) {
    FILE *file = fopen(filepath, "rb");
    if (file == NULL) {
        printf("n/a\n");
        return;
    }

    FILE *temp_file = fopen("temp.bin", "wb");
    if (temp_file == NULL) {
        fclose(file);
        printf("n/a\n");
        return;
    }

    Data record;
    int found = 0;

    while (fread(&record, sizeof(Data), 1, file) == 1) {
        if (!is_date_in_range(record, start_date, end_date)) {
            fwrite(&record, sizeof(Data), 1, temp_file);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp_file);

    if (found) {
        remove(filepath);
        rename("temp.bin", filepath);
    } else {
        remove("temp.bin");
    }
}
