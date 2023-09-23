#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

Cliente* criaClienteLista(void){
    return NULL;
}

void leDadosCliente(Cliente* novo){
    printf("Digite a cnh do Cliente: \n");
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

    for(p = cliente; p != NULL; p = p->prox){
        printf(" cnh: %d || nome: %s || telefone: %d \n", p->cnh, p->nome, p->telefone);
    }
}