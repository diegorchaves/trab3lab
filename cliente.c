#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente* criaClienteLista(void){
    return NULL;
}

void leDadosCliente(Cliente* novo){
    printf("Digite a CNH do Cliente: \n");
    scanf(" %d", &novo->cnh);
    getchar();
    printf("Digite o nome do Cliente: \n");
    fgets(novo->nome, sizeof(novo->nome), stdin);
    printf("Digite o telefone do Cliente: \n");
    scanf(" %d", &novo->telefone);
}

Cliente* incluiCliente(Cliente* cliente)
{
    Cliente* novo = (Cliente*) malloc(sizeof(Cliente));
    leDadosCliente(novo);
    novo->prox = cliente;

    return novo;
}

void imprimeCliente(Cliente* cliente){
    Cliente* p;
    int i = 0;

    for(p = cliente; p != NULL; p = p->prox){
        i++;
        printf("\nCliente %d: \nNome: %sCNH: %d\nTelefone: %d\n", i, p->nome, p->cnh, p->telefone);
    }
}

Cliente *procuraCliente(char nome[30], Cliente *clienteLista)
{
    Cliente *p;

    for (p = clienteLista; p != NULL; p = p->prox)
    {
        if (strcmp(nome, p->nome) == 0)
        {
            return p;
        }
    }

    return NULL;
}