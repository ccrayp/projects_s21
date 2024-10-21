#include "list.h"

struct Node* init(struct Door* door) {
    Node* list = (Node*)malloc(sizeof(Node));

    list->door = door;
    list->next = NULL;

    return list;
}

struct Node* add_door(struct Node* elem, struct Door* door) {
    struct Node* new = (Node*)malloc(sizeof(Node));

    new->door = door;
    new->next = elem->next;

    elem->next = new;

    return new;
}

struct Node* find_door(int door_id, struct Node* root) {
    struct Node* curr = root;
    int flag = 1;
    while (curr != NULL && flag) {
        if (curr->door->id == door_id) flag = 0;
        if (flag) curr = curr->next;
    }
    return curr;
}
void remove_door(const struct Node* elem, struct Node** root) {
    if (*root == NULL || elem == NULL) return;

    struct Node* curr = *root;
    struct Node* prev = NULL;

    while (curr != NULL && curr != elem) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) return;

    if (prev == NULL) {
        *root = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr);
}

void output_list(Node* list) {
    if (list == NULL) {
        printf("List is empty\n");
    } else {
        Node* curr = list;
        while (curr != NULL) {
            if (curr->next != NULL)
                printf("Door ID: %d, Status: %d\n", curr->door->id, curr->door->status);
            else
                printf("Door ID: %d, Status: %d", curr->door->id, curr->door->status);
            curr = curr->next;
        }
    }
}

void destroy(Node* root) {
    if (!root) return;
    destroy(root->next);
    free(root);
}

void push(Node** list, Door* door) {
    if (*list == NULL) {
        *list = init(door);
    } else {
        Node* curr = *list;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        add_door(curr, door);
    }
}
