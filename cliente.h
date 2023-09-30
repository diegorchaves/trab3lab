#include <stdlib.h>

typedef struct cliente 
{
    int cnh;
    char nome[30];
    int telefone;
    struct cliente *prox;
} Cliente;

Cliente *procuraCliente (char *nomeLocal, Cliente *lstClientes);

void leDadosCliente (Cliente *novo);

Cliente *incluiCliente (Cliente *lstClientes);

void imprimeClientes (Cliente *lstClientes);