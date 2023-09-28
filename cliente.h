#include <stdlib.h>

typedef struct cliente 
{
    int cnh;
    char nome[30];
    int telefone;
    struct cliente *prox;
} Cliente;

Cliente *procuraCliente (char *nomeLocal, Cliente *listaClientes);

void leDadosCliente (Cliente *novo);

Cliente *incluiClientes (Cliente* listaClientes);

void listarClientes (Cliente *listaClientes);