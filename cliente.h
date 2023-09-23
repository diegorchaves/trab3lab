#include <stdio.h>
#include <stdlib.h>

struct cliente{
    int cnh;
    char nome[30];
    int telefone;
    struct cliente* prox;
};
typedef struct cliente Cliente;

Cliente* criaClienteLista(void);

void leDadosCliente(Cliente* novo);

Cliente* incluiCliente(Cliente* cliente);

void imprimeCliente(Cliente* cliente);