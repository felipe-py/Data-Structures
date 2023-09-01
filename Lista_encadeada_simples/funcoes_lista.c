#include <stdio.h>
#include <stdlib.h>
#include "funcoes_lista.h"

typedef struct Ligacao{

    int dado;
    struct Ligacao* prox;

}Ligacao;

typedef struct LISTA{

    Ligacao* ini;
    Ligacao* fim;

}LISTA;

LISTA l;

void menu() {
    printf("\n=-=-=-=-=- [LISTA ENCADEADA SIMPLES] -=-=-=-=-=\n");
    printf("\n[1] - INSERIR NO INICIO DA LISTA\n");
    printf("[2] - INSERIR NO FIM DA LISTA\n");
    printf("[3] - EXIBIR LISTA\n");
    printf("[4] - REMOVER PRIMEIRO ELEMENTO DA LISTA\n");
    printf("[5] - ENCONTRAR ELEMENTO NA LISTA\n");
    printf("[6] - APAGAR LISTA\n");
    printf("[7] - NUMERO DE ELEMENTOS DA LISTA\n");
    printf("[8] - NUMEROS MAIORES QUE'N'\n");
    printf("[9] - TROCAR ELEMENTOS DA LISTA\n");
    printf("[10] - REMOVER ULTIMO ELEMENTO DA LISTA\n");
    printf("[11] - FREQUENCIA DE UM ELEMENTO\n");
    printf("[12] - ULTIMA APARICAO DE UM VALOR\n");
    printf("[0] - ENCERRAR PROGRAMA\n");
    printf("\n[ESCOLHA UMA OPCAO]\n");
}

void inserir_inicio(int elemento) {

    Ligacao *ptr = (Ligacao*) malloc(sizeof(Ligacao));
    ptr->dado = elemento;
    ptr->prox = NULL;

    if(l.ini == NULL) {
        l.fim = ptr;
    } else {
        ptr->prox = l.ini;
    }
    l.ini = ptr;

}

void inserir_fim(int elemento) {

    Ligacao *ptr = (Ligacao*) malloc(sizeof(Ligacao));
    ptr->dado = elemento;
    ptr->prox = NULL;

    if (l.ini == NULL) {
        l.ini = ptr;
    } else {
        l.fim->prox = ptr;
    }
    l.fim = ptr;

}

int remover_inicio() {

    Ligacao* ptr = l.ini;
    int elemento;

    if(ptr == NULL) {
        printf("\n>>> Lista vazia <<<\n");
        return -1;
    } else {
        l.ini = l.ini->prox;
        ptr->prox = NULL;
        elemento = ptr->dado;
        free(ptr);
        return elemento;
    }
}

void remover_fim(){
    Ligacao* ptr = l.ini;
    Ligacao* anterior = NULL;

    if(ptr == NULL){
        printf("\n [LISTA VAZIA]\n");
        return;
    } else {
        while(ptr->prox != NULL){
            anterior = ptr;
            ptr = ptr->prox;
        }
    }

    if(anterior == NULL){
        l.ini = NULL;
        l.fim = NULL;
    } else {
        anterior->prox = NULL;
        l.fim = anterior;
    }
    free(ptr);
}

void exibir_lista() {

    Ligacao* ptr = l.ini;
    if(ptr == NULL){
        printf("\nLISTA VAZIA\n");
    } else {
        printf("INICIO=> ");
    while(ptr != NULL) {
        printf("%d ",ptr->dado);
        ptr = ptr->prox;
    }
    printf(" <=FIM\n");
    }
}

Ligacao* encontrar_elemento(int elemento){
    Ligacao* ptr = l.ini;

    if(ptr == NULL){
        printf("\nERRO => LISTA VAZIA\n");
    } else {
        while(ptr != NULL){
        if(ptr->dado == elemento){
            printf("\nELEMENTO ENCONTRADO\n");
            return ptr;
        }
        ptr = ptr->prox;    
    }
    printf("\nERRO\\\n");
    }
}

void apagar_lista(){
    Ligacao* ptr = l.ini;

    if(ptr == NULL){
        printf("\nERRO => LISTA VAZIA\n");
    } else {
        l.ini = NULL;
        l.fim = NULL;
    }
}

int n_elementos_lista(){
    int soma = 0;
    Ligacao* ptr = l.ini;
    if(ptr == NULL){
        printf("LISTA VAZIA\n");
    } else {
        while(ptr != NULL){
            soma += 1;
            ptr = ptr->prox;
        }
    }
    return soma;
}

int maiores_que_n(int numero){
    int soma = 0;
    Ligacao* ptr = l.ini;
    if(ptr == NULL){
        printf("LISTA VAZIA\n");
    } else {
        while(ptr != NULL){
            if(ptr->dado > numero){
                soma += 1;
            }
            ptr = ptr ->prox;
        }
    }
    return soma;
}

void troca_elemento(int numero_original, int numero_novo){
    Ligacao* ptr = l.ini;
    if(ptr == NULL){
        printf("LISTA VAZIA\n");
    } else {
        while(ptr != NULL){
            if(ptr->dado == numero_original){
                ptr->dado = numero_novo;
            }
            ptr = ptr->prox;
        }
    }
}

int frequencia_valor(int elemento){
    Ligacao* ptr = l.ini;
    int frequencia = 0;
    
    if(ptr == NULL){
        printf("LISTA VAZIA\n");
    } else {
        while(ptr != NULL){
            if(ptr->dado == elemento){
                frequencia += 1;
            }
            ptr = ptr->prox;
        }
    }
    return frequencia;
}

Ligacao* ultima_aparicao_de_n(int x){
    int frequencia = frequencia_valor(x);
    Ligacao* ptr = l.ini;
    int soma = 0;

    if(ptr == NULL){
        printf("LISTA VAZIA\n");
    } else {
        while(ptr != NULL){
            if(ptr->dado == x){
                soma += 1;
            }
            if(soma == frequencia){
                return ptr;
            }
            ptr = ptr->prox;
        }
    }
}