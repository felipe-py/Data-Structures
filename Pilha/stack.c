#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct node{
    float info;
    struct node* prox;
};
typedef struct node Node;

struct stack{
    Node* first;
};

Stack* create(void){

    Stack* p = (Stack*) malloc(sizeof(Stack));
    p->first = NULL;
    return p;

}

Node* insert_at_start(Node* l, float v){

    Node* p = (Node*) malloc(sizeof(Node));
    if (p == NULL){
        printf("ERROR: memory allocation failed\n");
        exit(1);
    }
    p->info = v;
    p->prox = l;
    return p;

}

void push(Stack* p, float v){

    p->first = insert_at_start(p->first,v);

}

Node* remove_at_start(Node* l){

    Node* p = l->prox;
    free((void*)l);
    return p;

}

float pop(Stack* p){

    float v;
    if(empty(p)){
        printf("EMPTY STACK\n");
        exit(1);
    }
    v = p->first->info;
    p->first = remove_at_start(p->first);
    return v;
}

int empty(Stack* p){

    return p->first == NULL;

}

void free_stack(Stack* p){

    Node* q = p->first;
    while(q != NULL){
        Node* t = q->prox;
        free((void*)q);
        q = t;
    }
    free(p);
}

void display_stack(Stack* p){

    Node* q;
    for(q = p->first; q != NULL; q = q->prox){
        printf("%.1f\n",q->info);
    }

}

float top_of_stack(Stack* p){

    float v = pop(p);
    push(p,v);
    return v;
    
}

void concatenate_stack(Stack* p1, Stack* p2){

    Stack* conca = create();

    while(!empty(p2))
        push(conca,pop(p2));
    while(!empty(conca))
        push(p1,pop(conca));
    free(conca);

}

Stack* copy_stack(Stack* p1){

    Stack* aux = create();
    Stack* copy = create();
    float v;

    while(!empty(p1))
        push(aux,pop(p1));
    
    while(!empty(aux)){
        v = pop(aux);
        push(copy,v);
        push(p1,v);
    }

    free(aux);
    return copy;
}

int equal_stacks(Stack* p1, Stack* p2){

    Stack* aux1 = create();
    Stack* aux2 = create();
    float v1;
    float v2;
    int a = 1;

    while(!empty(p1) && !empty(p2)){
        push(aux1,pop(p1));
        push(aux2,pop(p2));
    }

    while(!empty(aux1) && !empty(aux2)){
        v1 = pop(aux1);
        v2 = pop(aux2);
        if(v1 != v2)
            a = 0;
        push(p1,v1);
        push(p2,v2);
    }
    return a;
}

void remove_odd(Stack* p){

    Stack* aux = create();
    int v;

    while(!empty(p))
        push(aux,pop(p));
    
    while(!empty(aux)){
        v = pop(aux);
        if(v % 2 == 0){
            push(p,v);
        }
    }
}