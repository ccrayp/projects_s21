#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

typedef struct Node {
    Door* door;
    struct Node* next;
} Node;

Node* init(Door* door);
Node* add_door(Node* elem, Door* door);
Node* find_door(int door_id, Node* root);
void remove_door(const Node* elem, Node** root);
void destroy(Node* root);
void output_list(Node* list);
void push(Node** list, Door* door);

#endif
