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

    free(bst);

    printf("Test 2:\ninput: 876545\noutput: ");
    bst = bstree_create_node(876545);
    printf("%d\n", bst->item);
    if (bst->item == 876545)
        printf("SUCCESS");
    else
        printf("FAIL");

    free(bst);

    return 0;
}
