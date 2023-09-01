#include <stdio.h>
#include <stdlib.h>
#include "funcoes_lista.c"

int main() {

    int opcao, dado, n_troca;
    Ligacao* resultado;

    l.ini = NULL;
    l.fim = NULL;

    do{

        menu();
        scanf("%d",&opcao);
        fflush(stdin);
        printf("\n");
        switch (opcao)
        {
        case 1:
            
            printf("Informe o dado que sera inserido no inicio: ");
            scanf("%d",&dado);
            fflush(stdin);
            inserir_inicio(dado);
            break;

        case 2:
            
            printf("Informe o dado que sera inserido no fim: ");
            scanf("%d",&dado);
            fflush(stdin);
            inserir_fim(dado);
            break;

        case 3:
            
            exibir_lista();
            break;

        case 4:
           
            dado = remover_inicio();
            if (dado == -1) {
                printf("\nErro.\\\n");
            } else {
                printf("\nO elemento %d foi removido do inicio da lista\n",dado);
            }
            break;

        case 5:
            
            printf("DIGITE O NUMERO QUE DESEJA ENCONTRAR NA LISTA: ");
            scanf("%d",&dado);
            printf("ENDERECO DO ELEMENTO => %p\n",encontrar_elemento(dado));
            break;

        case 6:
            
            apagar_lista();
            printf(">>> [A LISTA FOI APAGADA] <<<\n");
            exibir_lista();
            break;

        case 7:
            
            printf("A LISTA POSSUI %d NUMEROS\n",n_elementos_lista());
            break;

        case 8:
           
            printf("DIGITE O NUMERO PARA PESQUISA: ");
            scanf("%d",&dado);
            printf("\nNUMERO DE VALORES MAIORES QUE %d => %d\n",dado,maiores_que_n(dado));
            break;

        case 9:
            
            printf("DIGITE O NUMERO QUE SERA RETIRADO DA LISTA: ");
            scanf("%d",&dado);
            printf("DIGITE O NUMERO QUE SERA INSERIDO NO LOCAL: ");
            fflush(stdin);
            scanf("%d",&n_troca);
            troca_elemento(dado,n_troca);
            printf("\nA TROCA FOI REALIZADA\n");
            exibir_lista();
            break;
        
        case 10:

            exibir_lista();
            printf("O ULTIMO ELEMENTO DA LISTA SERA REMOVIDO\n");
            remover_fim();
            exibir_lista();
            break;

        case 11:

            printf("DIGITE O VALOR QUE DESEJA PESQUISAR NA LISTA: ");
            scanf("%d",&dado);
            fflush(stdin);
            printf("\n >>> O NUMERO %d APARECE %d VEZES NA LISTA\n",dado, frequencia_valor(dado));
            break;

        case 12:

            printf("DIGITE O NUMERO PARA PESQUISA: ");
            scanf("%d",&dado);
            fflush(stdin);
            printf("\n >>> A ULTIMA POSICAO DO NUMERO %d FICA NO ESPACO %p\n >>> [VALOR => %d] <<<\n",dado,ultima_aparicao_de_n(dado),*ultima_aparicao_de_n(dado));

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