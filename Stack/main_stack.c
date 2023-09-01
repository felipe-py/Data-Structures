#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

int main(){

    Stack* q = create();
    Stack* q2 = create();
    Stack* copy = NULL;

    //STACK NUMBER ONE

    push(q,6);
    push(q,5);
    push(q,4);
    push(q,7);
    push(q,10);
    //pop(q);
    //display_stack(q);
    //printf("The number %.1f is in the top of stack number one\n\n",top_of_stack(q));

    //STACK NUMBER TWO

    push(q2,6);
    push(q2,5);
    push(q2,4);
    //pop(q2);
    //display_stack(q2);
    //printf("The number %.1f is in the top of stack number two\n",top_of_stack(q2));

    /*printf("\n\n");
    concatenate_stack(q,q2);
    display_stack(q);*/

    /*printf("\n\n");
    copy = copy_stack(q);
    display_stack(copy);*/

    /*if(equal_stacks(q,q2))
        printf("THE STACKS ARE EQUALS\n");
    else
        printf("THE STACKS ARE DIFERENTS\n\n");
    return 0;*/

    remove_odd(q);
    free_stack(q);
    display_stack(q);

}