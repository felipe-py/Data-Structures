#include <stdio.h>
#include <stdio.h>
#include "tree.c"

int main(){

    Tree* t = start();
    t = insert(t,15);
    t = insert(t,27);
    t = insert(t,49);
    t = insert(t,10);
    t = insert(t,8);
    t = insert(t,67);
    t = insert(t,59);
    t = insert(t,9);
    t = insert(t,13);
    t = insert(t,20);
    t = insert(t,14);

    printf("INORDER\n");
    inorder(t);
    printf("\n\nPOSTORDER\n");
    postorder(t);
    printf("\n\nPREORDER\n");
    preorder(t);

    printf("\n\nNUMBER OF NODES\n");
    printf("%d",n_nodes(t));

    printf("\n\nHEIGHT OF THE TREE\n");
    printf("%d",tree_height(t));

    printf("\n\nNUMBER OF NODES WITH EVEN NUMBERS\n");
    printf("%d",even_numbers(t));

    printf("\n\nNUMBER OF VALUES GREATER THAN 15\n");
    printf("%d",greater_thanx(t,15));

    printf("\n\nNUMBER OF LEAVES IN THE TREE\n");
    printf("%d",n_leaves(t));

    printf("\n\nNUMBER OF NODES WITH ONE SON\n");
    printf("%d",n_nodesONE(t));

    printf("\n\nNUMBER OF NODES THAT DON'T ARE LEAVES\n");
    printf("%d",n_not_leaves(t));

    printf("\n\n");
    t = remove_info(t,20);
    inorder(t);

    return 0;
}