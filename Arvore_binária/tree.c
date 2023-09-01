#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


struct tree {
    int value;
    struct tree* left_child;
    struct tree* right_child;
};

Tree* start(void){
    return NULL;
}

//DISPLAY METHODS

void inorder(Tree* a) {
    if (a == NULL) {
        return;
    }
    
    inorder(a->left_child);
    printf("%d ", a->value);
    inorder(a->right_child);

}

void preorder(Tree* a) {
    if (a == NULL) {
        return;
    }
    
    printf("%d ", a->value);
    preorder(a->left_child);
    preorder(a->right_child);
}

void postorder(Tree* a) {
    if (a == NULL) {
        return;
    }
    
    postorder(a->left_child);
    postorder(a->right_child);
    printf("%d ", a->value);
}

Tree* search(Tree* a, int v) {
    if (a == NULL || a->value == v) {
        return a;
    } else if (v < a->value) {
        return search(a->left_child, v);
    } else {
        return search(a->right_child, v);
    }
}

Tree* insert(Tree* a, int v) {
    if (a == NULL) {
        a = (Tree*) malloc(sizeof(Tree));
        a -> value = v; 
        a->left_child = a->right_child = NULL;
    } else if (v < a->value) {
        a->left_child =  insert(a->left_child, v);
    } else {
        a->right_child =  insert(a->right_child, v);
    }
    return a;
}

Tree* remove_info(Tree* a, int v){

    if(a == NULL) return NULL;
    else if(a->value > v) a->left_child = remove_info(a->left_child,v);
    else if(a->value < v) a->right_child = remove_info(a->right_child,v);
    else{
        if(a->left_child == NULL && a->right_child){
            free(a);
            a = NULL;
        } else if(a->left_child == NULL) {
            Tree* t = a;
            a = a->right_child;
            free(t);
        } else if(a->right_child == NULL) {
            Tree* t = a;
            a = a->left_child;
            free(t);
        } else {
            Tree* father = a;
            Tree* f = a->left_child;
            while(f->right_child != NULL){
                father = f;
                f = f->right_child;
            }
            a->value = f->value;
            f->value = v;
            a->left_child = remove_info(a->left_child,v);
        }
    }
    return a;
}

int empty(Tree*a){
    return a == NULL;
}

int tree_height(Tree* a){

    if(a == NULL){
        return 0;
    }else {
        int h_left = tree_height(a->left_child);
        int h_right = tree_height(a->right_child);
        if(h_left > h_right)
            return h_left + 1;
        else
            return h_right + 1;
    }
}

int n_nodes(Tree* a){

    if(a == NULL){
        return 0;
    } else {
        int n_left = n_nodes(a->left_child);
        int n_right = n_nodes(a->right_child);
        return n_left + n_right + 1;
    }
}

int even_numbers(Tree* a){

    if(a == NULL){
        return 0;
    } else {
        int n_left = even_numbers(a->left_child);
        int n_right = even_numbers(a->right_child);
        int count = n_left + n_right;
        if(a->value % 2 == 0) { 
            count++;
        }
        return count;
    }
}

int greater_thanx(Tree*a, int x){

    if(a == NULL){
        return 0;
    } else {
        int n_left = greater_thanx(a->left_child, x);
        int n_right = greater_thanx(a->right_child, x);
        int count = n_left + n_right;
        if(a->value > x){
            count ++;
        }
        return count;
    }
}

int n_leaves(Tree* a){

    if (a == NULL) {
        return 0;
    } else if (a->left_child == NULL && a->right_child == NULL) {
        return 1;
    } else {
        int left_leaves = n_leaves(a->left_child);
        int right_leaves = n_leaves(a->right_child);
        return left_leaves + right_leaves;
    }
}

int n_nodesONE(Tree* a){

    if (a == NULL) {
        return 0;
    } else if (a->left_child == NULL && a->right_child != NULL) {
        return 1 + n_nodesONE(a->right_child);
    } else if (a->left_child != NULL && a->right_child == NULL) {
        return 1 + n_nodesONE(a->left_child);
    } else {
        return n_nodesONE(a->left_child) + n_nodesONE(a->right_child);
    }
}

int n_not_leaves(Tree* a){
    if (a == NULL || (a->left_child == NULL && a->right_child == NULL)) {
        // If the current node is null or a leaf, return 0
        return 0;
    } else {
        // If the current node is not a leaf, count it and recurse on its children
        int left_not_leaves = n_not_leaves(a->left_child);
        int right_not_leaves = n_not_leaves(a->right_child);
        return left_not_leaves + right_not_leaves + 1;
    }
}
