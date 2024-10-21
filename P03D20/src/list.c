#include "list.h"

List *list_init() {
    List *list = (List *)malloc(sizeof(List));
    if (list) {
        list->array = (Element *)malloc(sizeof(Element) * START_SIZE_LIST);
        if (list->array) {
            list->size = 0;
            list->real_size = START_SIZE_LIST;
        } else {
            free(list);
            list = NULL;
        }
    }

    return list;
}

int list_add(List *list, Element item) {
    int error = 0;
    if (!list) error++;

    if (!error && (list->size + 1 > list->real_size)) {
        Element *new_array =
            (Element *)realloc(list->array, list->real_size * RESIZE_LIST_FACTOR * sizeof(Element));
        if (!new_array)
            error++;
        else {
            list->array = new_array;
            list->real_size = list->real_size * RESIZE_LIST_FACTOR;
        }
    }

    if (!error) {
        list->array[list->size] = item;
        list->size += 1;
    }

    return error;
}

Element list_get(List *list, int index) {
    Element ans = {ERROR, 0, 0, 0};

    if (list && (-list->size <= index) && (index < list->size)) {
        if (index < 0) index += list->size;
        ans = list->array[index];
    }

    return ans;
}

void list_destroy(List *list) {
    if (!list) return;

    free(list->array);
    free(list);
}
