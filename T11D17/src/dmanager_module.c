#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct Door* doors);
void sort(struct Door* doors);

int main() {
    struct Door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort(doors);
    for (int i = 0; i < DOORS_COUNT; i++) {
        if (i != DOORS_COUNT - 1)
            printf("%d, %d\n", doors[i].id, doors[i].status);
        else
            printf("%d, %d", doors[i].id, doors[i].status);
    }
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!

void sort(struct Door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        for (int j = 0; j < DOORS_COUNT; j++) {
            if (doors[i].id < doors[j].id) {
                struct Door temp = doors[i];
                doors[i] = doors[j];
                doors[j] = temp;
            }
        }
    }
}

void initialize_doors(struct Door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}
