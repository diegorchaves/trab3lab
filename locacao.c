#include <stdio.h>
#include <stdlib.h>
#include "veiculo.h"
#include "cliente.h"
#include "locacao.h"
#include "data.h"


Locacao *criaLocacaoLista(void)
{
    return NULL;
}

int estaLocado(Veiculo* veiculo, Locacao* listaLocacao, struct Date *retirada, struct Date *devolucao){
    Locacao* p;

    // PERCORRE LISTA DE LOCACOES ATE ENCONTRAR O VEICULO QUE FOI PASSADO
    for(p = listaLocacao; p != NULL; p = p->prox){  
        if(p->veiculo == veiculo){ // VERIFICA SE O VEICULO ESTA LOCADO NA DATA PASSADA
            if(!(daysBetweenDates(*p->devolucao, *retirada) > 0 || daysBetweenDates(*devolucao, *p->retirada) > 0)){
                return 1; // ESTA LOCADO
            }
        }
    }

    return 0; // NAO ESTA
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
    char placaLocal[9];
    getchar();
    do
    {
        printf("Digite o nome do cliente: ");
        fgets(nomeLocal, sizeof(nomeLocal), stdin);
        novo->cliente = procuraCliente(nomeLocal, clienteLista);
    } while (novo->cliente == NULL);

    // PEGA DATAS DE RETIRADA E DEVOLUCAO 
    printf("Digite a data da locacao (DD MM AAAA): ");
    scanf("%d %d %d", &novo->retirada->day, &novo->retirada->month, &novo->retirada->year);

    printf("Digite a data da devolucao (DD MM AAAA): ");
    scanf("%d %d %d", &novo->devolucao->day, &novo->devolucao->month, &novo->devolucao->year);

    // PREPARA PARA EXBIRIR LISTA DE CARROS DISPONIVEIS
    Veiculo* p;
    if(veiculoLista == NULL){ // LISTA DE VEICULOS VAZIA
        printf("sem veiculos\n");
    }

    for(p = veiculoLista; p != NULL; p = p->prox){
        if(estaLocado(p, listaLocacao, novo->retirada, novo->devolucao) == 0){ //PASSA TODA LISTA VEICULO PARA A FUNCAO QUE VERIFICA SE N ESTA LOCADO
            printf("Veiculo Diponivel: %s , PLACA: %s \n", p->modelo, p->placa);
        }
    }

    // ESCOLHE UM VEICULO PELA PLACA 
    getchar();
    do
    {
        printf("Digite a placa do carro ");
        fgets(placaLocal, sizeof(placaLocal), stdin);
        novo->veiculo = procuraVeiculo(placaLocal, veiculoLista);
    } while (novo->veiculo == NULL);
    

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
