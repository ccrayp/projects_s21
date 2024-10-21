#include <stdio.h>
#include "bst.h"

int main() {
    printf("**************MAKE ROOT**************\n");
    t_btree* root = bstree_create_node(4);
    printf("SUCCESS\n");
    printf("**************ADD LEAVES**************\n");
    bstree_insert(&root, 2, &cmpf);
    bstree_insert(&root, 6, &cmpf);
    bstree_insert(&root, 1, &cmpf);
    bstree_insert(&root, 3, &cmpf);
    bstree_insert(&root, 5, &cmpf);
    bstree_insert(&root, 7, &cmpf);
    printf("SUCCESS\n");
    printf("**************OUTPUT PREFIX**************\n");
    printf("prefix: ");
    bstree_apply_prefix(root, applyf);
    printf("\nSUCCESS\n");
    printf("**************OUTPUT INFIX**************\n");
    printf("\ninfix: ");
    bstree_apply_infix(root, applyf);
    printf("\nSUCCESS\n");
    printf("**************OUTPUT POSTFIX**************\n");
    printf("\npostfix: ");
    bstree_apply_postfix(root, applyf);
    printf("\nSUCCESS\n");

    bstree_destroy(root);
    return 0;
}
