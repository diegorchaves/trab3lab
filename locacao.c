#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"
#include "cliente.h"
#include "locacao.h"
#include "data.h"


Locacao *criaLocacaoLista(void)
{
    return NULL;
}


int calculaValorPago(Veiculo* veiculo, struct Date *retirada, struct Date *devolucao){
    int dias;

    dias = daysBetweenDates(*retirada, *devolucao);

    return veiculo->diaria * dias;

}


void leDadosLocacao(Locacao* listaLocacao, Locacao *novo, Cliente *clienteLista, Veiculo *veiculoLista)
{
    // PEGA NOME DO CLIENTE
    char nomeLocal[30];
    
    getchar();
    do
    {
        printf("Digite o nome do cliente: ");
        fgets(nomeLocal, sizeof(nomeLocal), stdin);
        novo->cliente = procuraCliente(nomeLocal, clienteLista);
    } while (novo->cliente == NULL);

    // PEGA DATAS DE RETIRADA E DEVOLUCAO 
    printf("Digite a data de hoje (DD MM AAAA): ");
    scanf("%d %d %d", &novo->retirada->day, &novo->retirada->month, &novo->retirada->year);

    printf("Digite a data da devolucao (DD MM AAAA): ");
    scanf("%d %d %d", &novo->devolucao->day, &novo->devolucao->month, &novo->devolucao->year);

    // PREPARA PARA EXBIRIR LISTA DE CARROS DISPONIVEIS
    if(veiculoLista == NULL){ // LISTA DE VEICULOS VAZIA
        printf("sem veiculos\n");
    }
    imprimeVeiculoDisponiveis(veiculoLista);

    // ESCOLHE UM VEICULO PELA PLACA 
    char placaLocal[8];
    do
    {
        getchar ();
        printf("Digite a placa do carro ");
        fgets(placaLocal, sizeof(placaLocal), stdin);
        novo->veiculo = procuraVeiculo(placaLocal, veiculoLista);
    } while (novo->veiculo == NULL);
    
    // TIRA DISPONIBILIDADE
    novo->veiculo->disponivel = 0;
    // CALCULA VALOR PAGO
    novo->valorPago = calculaValorPago(novo->veiculo, novo->retirada, novo->devolucao);
}

Locacao *incluiLocacao(Locacao *locacao, Cliente *clienteLista, Veiculo *veiculoLista)
{
    Locacao *novo = (Locacao *)malloc(sizeof(Locacao));
    novo->retirada = malloc(sizeof(int) * 3);
    novo->devolucao = malloc(sizeof(int) * 3);
    leDadosLocacao(locacao, novo, clienteLista, veiculoLista);
    novo->prox = locacao;

    return novo;
}

void imprimeLocacoes(Locacao* locacao){
    Locacao* p;

    for(p = locacao; p != NULL; p = p->prox){
        printf("cliente: %s || veiculo: %s || valor: %.2f \n", p->cliente->nome, p->veiculo->modelo, p->valorPago);
    }
}
