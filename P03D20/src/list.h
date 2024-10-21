#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

#include "element.h"

#define RESIZE_LIST_FACTOR 2
#define START_SIZE_LIST 16

typedef struct List {
    Element *array;
    int real_size;
    int size;
} List;

List *list_init();
int list_add(List *list, Element item);
Element list_get(List *list, int ind);
void list_destroy(List *list);

#endif
