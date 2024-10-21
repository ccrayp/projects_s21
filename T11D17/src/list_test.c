#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(Door* doors);

int main() {
    Door doors[DOORS_COUNT];
    initialize_doors(doors);
    Node* list = NULL;

    printf("*************INPUT DOORS ARRAY*************\n");
    for (int i = 0; i < DOORS_COUNT; i++) {
        push(&list, &doors[i]);
    }
    printf("SUCCESS\n");
    printf("*************OUTPUT LIST*************\n");
    output_list(list);
    printf("\nSUCCESS\n");
    printf("*************OUTPUT DOOR WITH ID 5*************\n");
    Node* finded = find_door(5, list);
    printf("%d, %d\nSUCCESS\n", finded->door->id, finded->door->status);
    printf("*************DELETE DOOR WITH ID 5*************\n");
    remove_door(finded, &list);
    printf("SUCCESS\n");
    printf("*************OUTPUT UPDATED LIST*************\n");
    output_list(list);
    printf("\nSUCCESS\n");
    printf("*************DESTROING LIST*************\n");
    destroy(list);
    printf("SUCCESS\n");
    list = NULL;
    printf("*************OUTPUT DESTROED LIST*************\n");
    output_list(list);
    printf("SUCCESS\n");
    return 0;
}

void initialize_doors(Door* doors) {
    srand(time(0));

    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = i;
        doors[i].status = rand() % 2;
    }
}
