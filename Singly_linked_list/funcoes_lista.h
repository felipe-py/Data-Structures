#ifndef funcoes_lista_h
#define funcoes_lista_h

typedef struct Ligacao Ligacao;
typedef struct LISTA LISTA;
Ligacao* encontrar_elemento();
Ligacao* ultima_aparicao_de_n();
void menu();
void inserir_inicio();
void inserir_fim();
int remover_inicio();
void remover_fim();
void exibir_lista();
void apagar_lista();
int n_elementos_lista();
int maiores_que_n();
void troca_elemento();
int frequecia_valor();

#endif