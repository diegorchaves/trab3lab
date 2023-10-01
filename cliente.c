#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente *procuraCliente (char *nomeLocal, Cliente *lstClientes)
{
    Cliente *p;
    for (p = lstClientes; p != NULL; p = p->prox)
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

Cliente *incluiCliente (Cliente *lstClientes)
{
    Cliente *novo = (Cliente*)malloc(sizeof(Cliente));
    leDadosCliente (novo);
    novo->prox = lstClientes;
    return novo;
}

void imprimeClientes (Cliente *lstClientes)
{
    Cliente *p = lstClientes;
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

