#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"
#include "cliente.h"
#include "locacao.h"
#include "data.h"

Locacao* criaLocacaoLista(void){
    return NULL;
}

Cliente* procuraCliente(char nome[30], Cliente* clienteLista){
    Cliente* p;

    for(p = clienteLista; p != NULL; p = p->prox){
        if(strcmp(nome, p->nome) == 0){
            return p;
        }
    }

    return NULL;
}

void leDadosLocacao(Locacao* novo, Cliente* clienteLista, Veiculo* veiculoLista){
    // char nomeLocal[30];

    // do{
    //     getchar();
    //     printf("Digite o nome do cliente: ");
    //     fgets(nomeLocal, sizeof(nomeLocal), stdin);
    //     novo->cliente = procuraCliente(nomeLocal, clienteLista);
    // }while(novo->cliente == NULL);


    ///ERRO AQUI 
    printf("Digite a data da locacao (DD MM AAAA): ");
    scanf("%d %d %d", &novo->retirada->day, &novo->retirada->month, &novo->retirada->year);

    printf("Digite a data da devolucao (DD MM AAAA): ");
    scanf("%d %d %d", &novo->devolucao->day, &novo->devolucao->month, &novo->devolucao->year);

    //imprimeVeiculoDisponiveis(veiculosLista, novo->retirada, novo->devolucao);

}

Locacao* incluiLocacao(Locacao* locacao, Cliente* clienteLista, Veiculo* veiculoLista)
{
    Locacao* novo = (Locacao*) malloc(sizeof(Locacao));
    leDadosLocacao(novo, clienteLista, veiculoLista);
    novo->prox = locacao;

    return novo;
}