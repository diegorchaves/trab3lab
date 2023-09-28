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

    printf ("\nListando CLientes...\n");
    Cliente *p;
    if(listaClientes == NULL){
        printf("Lista vazia \n");
    }else{
        for (p = listaClientes; p != NULL; p = p->prox)
        {   
            printf ("Nome: %s || ", p->nome);
            printf ("CNH: %d || ", p->cnh);
            printf ("Telefone: %d \n", p->telefone);
        }
    }
    
    
}