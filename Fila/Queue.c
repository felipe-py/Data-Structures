 #include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct list{
    float info;
    struct list* prox;
};
typedef struct list List;

struct queue{
    List* start;
    List* end;
};

Queue* create(void){
    
    Queue* f = (Queue*) malloc(sizeof(Queue));
    f->start = f->end = NULL;
    return f;
    
} 

List* insert_at_end(List* end, float v){

    List* p = (List*) malloc(sizeof(List));
    p->info = v;
    p->prox = NULL;

    if(end != NULL){
        end->prox = p;
    }
    return p;
}

List* remove_first(List* start){

    List* p = start->prox;
    free(start);
    if(p == NULL){
        return NULL;
    }
    return p;
}

void insert(Queue* f, float v){

    f->end = insert_at_end(f->end,v);
    if(f->start == NULL){
        f->start = f->end;
    }
}

float remove_queue(Queue* f){

    float v;
    if(empty(f)){
        printf("EMPTY QUEUE\n");
        exit(1);
    }

    v = f->start->info;
    f->start = remove_first(f->start);
    if(f->start == NULL){
        f->end = NULL;
    }
    return v;
}

int empty(Queue* f){
    
    return (f->start == NULL);

}

void free_queue(Queue* f){

    List* q = f->start;
    while(q != NULL){
        List* t = q->prox;
        free((void*)q);
        q = t;
    }
    f->start = f->end = NULL;
}

void display_queue(Queue* f){

    List* q;
    for(q = f->start; q != NULL; q = q->prox){
        printf("%.1f\n",q->info);
    }
}

void odd_even_queue(Queue* f, Queue* f_odd, Queue* f_even){

    while(!empty(f)){
        float v = remove_queue(f);
        if((int)v % 2 == 0){
            insert(f_even,v);
        } else {
            insert(f_odd,v);
        }
    }
    f->start = f->end = NULL;
}

void merge_queue(Queue* f_main, Queue* f1, Queue* f2){

    while(!empty(f1) && !empty(f2)){
        float v1 = remove_queue(f1);
        float v2 = remove_queue(f2);
        insert(f_main,v1);
        insert(f_main,v2);
    }
}

int equal_queue(Queue* f1, Queue* f2){

    Queue* aux1 = create();
    Queue* aux2 = create();
    int a = 1;

    while(!empty(f1) && !empty(f2)){
        float v1 = remove_queue(f1);
        float v2 = remove_queue(f2);
        insert(aux1,v1);
        insert(aux2,v2);  
    }
    while(!empty(aux1) && !empty(aux2)){
        float v1 = remove_queue(aux1);
        float v2 = remove_queue(aux2);
        if(v1 != v2)
            a = 0;
        insert(f1,v1);
        insert(f2,v2);  
    }

    return a;
}

Queue* copy_queue(Queue* f){

    Queue* aux = create();
    Queue* copy = create();
    float v;

    while(!empty(f)){
        v = remove_queue(f);
        insert(aux,v);
    }

    while(!empty(aux)){
        v = remove_queue(aux);
        insert(f,v);
        insert(copy,v);
    }
    free(aux);
    return copy;

}