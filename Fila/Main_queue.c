#include <stdio.h>
#include <stdlib.h>
#include "Queue.c"

int main(){

    Queue* f = create();
    Queue* f_odd = create();
    Queue* f_even = create();
    Queue* f1 = create();
    Queue* f2 = create();
    Queue* copy = create();

    printf("ADDING THE VALUES 5 - 2 - 7\n\n");
    insert(f,5);
    insert(f,2);
    insert(f,3);

    printf("REMOVING ELEMENT FROM QUEUE\n\n");
    printf("%.2f\n",remove_queue(f));
    printf("\n\n");
    display_queue(f);
    printf("\n\n");

    printf("ADDING THE VALUES 7 - 8 - 9\n\n");
    insert(f,7);
    insert(f,8);
    insert(f,9);

    display_queue(f);
    
    printf("DELETING QUEUE");
    free_queue(f);

    display_queue(f);

    printf("ADDING THE VALUES 22 - 17 - 13\n\n");
    insert(f,22);
    insert(f,17);
    insert(f,13);

    printf("\n\n");
    display_queue(f);
    printf("\n\n");
    printf("REMOVING ELEMENT FROM QUEUE\n\n");
    printf("%.2f",remove_queue(f));
    printf("\n\n");
    display_queue(f);

    printf("DELETING QUEUE\n\n");
    free_queue(f);

    printf("ADDING THE VALUES 23 - 10 - 11 - 66 - 33 - 78\n\n");
    insert(f,23);
    insert(f,10);
    insert(f,11);
    insert(f,66);
    insert(f,33);
    insert(f,78);
    
    printf("\n\n[EXERCISE NUMBER 2]\n\n");
    odd_even_queue(f, f_odd, f_even);
    printf("=-=- [EVEN QUEUE] -=-=\n");
    display_queue(f_even);
    printf("\n\n");
    printf("=-=- [ODD QUEUE] -=-=\n");
    display_queue(f_odd);
    printf("\n\n");

    printf("[EXERCISE NUMBER 3]\n\n");
    insert(f1,2.1);
    insert(f1,4.5);
    insert(f1,1.0);
    insert(f2,7.2);
    insert(f2,3.1);
    insert(f2,9.8);

    merge_queue(f, f1, f2);
    display_queue(f);

    printf("[EXERCISE NUMBER 4]\n\n");
    printf("ADDING THE VALUES 21 - 10 - 33\n\n");
    insert(f1,21);
    insert(f1,10);
    insert(f1,33);
    insert(f2,21);
    insert(f2,10);
    insert(f2,33);
    
    if(equal_queue(f1,f2))
        printf("THE QUEUE ARE EQUALS\n\n");
    else
        printf("THE QUEUE ARE DIFERENTS\n\n");
    
    printf("QUEUE 01\n\n");
    display_queue(f1);
    printf("\n\nQUEUE 02\n\n");
    display_queue(f2);

    printf("\n\n[EXERCISE NUMBER 4]\n\n");
    copy = copy_queue(f);
    printf("COPY QUEUE\n\n");
    display_queue(copy);
    printf("\nMAIN QUEUE\n\n");
    display_queue(copy);

    return 0;
}