#include <stdio.h>

#include "bst.h"

int main() {
    printf("Test 1:\ninput: 5\noutput: ");
    t_btree* bst = bstree_create_node(5);
    printf("%d\n", bst->item);
    if (bst->item == 5)
        printf("SUCCESS\n\n");
    else
        printf("FAIL\n\n");

    printf("Test 2:\ninput: 876545\noutput: ");
    bstree_insert(&bst, 876545, &cmpf);
    printf("%d\n", bst->right->item);
    if (bst->right->item == 876545)
        printf("SUCCESS\n\n");
    else
        printf("FAIL\n\n");

    printf("Test 3:\ninput: 2\noutput: ");
    bstree_insert(&bst, 2, &cmpf);
    printf("%d\n", bst->left->item);
    if (bst->left->item == 2)
        printf("SUCCESS");
    else
        printf("FAIL");

    free(bst->left);
    free(bst->right);
    free(bst);
    return 0;
}
