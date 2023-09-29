#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente *procuraCliente (char *nomeLocal, Cliente *listaClientes)
{
    Cliente *p;
    for (p = listaClientes; p != NULL; p = p->prox)
    {
        if (strcmp(nomeLocal, p->nome) == 0)
        {
            return p;
        }
    }
    return NULL;
}

void leDadosCliente (Cliente *novo)
{
    printf ("Digite a CNH do cliente: \n");
    scanf ("%d", &novo->cnh);
    getchar ();
    printf ("Digite o nome do cliente: \n");
    fgets (novo->nome, sizeof(novo->nome), stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0';
    printf ("Digite o telefone do cliente: \n");
    scanf ("%d", &novo->telefone);
}

Cliente *incluiClientes (Cliente* listaClientes)
{
    Cliente *novo = (Cliente*)malloc(sizeof(Cliente));
    leDadosCliente (novo);
    novo->prox = listaClientes;
    return novo;
}

void listarClientes (Cliente *listaClientes)
{
    Cliente *p = listaClientes;
    if (p == NULL)
    {
        printf ("Nao existem clientes cadastrados.\n");
    }
    else
    {
        while (p != NULL)
        {  
            printf ("Nome: %s || ", p->nome);
            printf ("CNH: %d || ", p->cnh);
            printf ("Telefone: %d\n", p->telefone);
            p = p->prox;
        }
        
    }
}