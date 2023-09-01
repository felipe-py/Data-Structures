#include <stdio.h>
#include <stdlib.h>

typedef struct Ligacao{
    int cpf;
    int numero_telefone;
    float salario;
    struct Ligacao* prox;
}Ligacao;

typedef struct Lista{
    Ligacao* inicio;
    Ligacao* fim;
}Lista;

Lista pessoa;

void inserir_no_inicio(int c_pf, int n_telefone, float ganho_mensal){
    Ligacao* ptr = (Ligacao*) malloc(sizeof(Ligacao));
    ptr->cpf = c_pf;
    ptr->numero_telefone = n_telefone;
    ptr->salario = ganho_mensal;
    ptr->prox = NULL;

    if(pessoa.inicio == NULL){
        pessoa.fim = ptr;
    } else {
        ptr->prox = pessoa.inicio;
    }
    pessoa.inicio = ptr;
}

void exibir_lista(){
    Ligacao* ptr = pessoa.inicio;
    int soma = 0;
    if(ptr == NULL){
        printf("\n [LISTA VAZIA]\n");
    } else {
        while(ptr != NULL){
            printf("\n>>> DADOS DA PESSOA %d <<<\n\nCPF => %d\nNUMERO DE TELEFONE => %d\nSALARIO => R$%.2f\n",soma+=1, ptr->cpf, ptr->numero_telefone, ptr->salario);
            ptr = ptr->prox;
        }
    }
}

void menu() {

    printf("\n[1] - INSERIR NO INICIO DA LISTA\n");
    printf("[2] - EXIBIR LISTA\n");
    printf("[0] - ENCERRAR PROGRAMA\n");
}

int main() {

    int opcao;
    int c_pf;
    int phone_number;
    float salary;
    Ligacao* resultado;

    pessoa.inicio = NULL;
    pessoa.fim = NULL;

    do{

        menu();
        scanf("%d",&opcao);
        fflush(stdin);
        printf("\n");
        switch (opcao)
        {
        case 1:
            
            printf("Informe os dados que serao inseridos no inicio da lista:\n\n>> DIGITE O CPF: ");
            scanf("%d",&c_pf);
            fflush(stdin);
            printf(">> DIGITE O NUMERO DE TELEFONE: ");
            scanf("%d",&phone_number);
            fflush(stdin);
            printf(">> DIGITE O SALARIO: ");
            scanf("%f",&salary);
            fflush(stdin);
            inserir_no_inicio(c_pf,phone_number,salary);
            break;

        case 2:
            
            exibir_lista();
            break;

        case 0:
            break;
        default:
            printf("\nOPCAO INVALIDA\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}