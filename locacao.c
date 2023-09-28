#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"
#include "locacao.h"
#include "cliente.h"
#include "datas.h"

Veiculo *realizaLocacao (char *placaLocal, Veiculo *listaVeiculos)
{
    Veiculo *p;
    for (p = listaVeiculos; p != NULL; p = p->prox)
    {
        if (p->disponivel == 1 && strcmp (placaLocal, p->placa) == 0)
        {
            p->disponivel = 0;
            return p;
        }
    }
    return NULL;
}

void leDadosLocacao (Locacao *listaLocacao, Locacao *novo, Cliente *listaClientes, Veiculo *listaVeiculos)
{
    char nomeLocal[30];
    char placaLocal[8];

    getchar ();
    do
    {
        printf ("Digite o nome do cliente: ");
        fgets (nomeLocal, sizeof(nomeLocal), stdin);
        novo->cliente = procuraCliente (nomeLocal, listaClientes);
    } while (novo->cliente == NULL);

    printf ("Digite a data de hoje (DD MM AAAA): ");
    scanf ("%d %d %d", &novo->retirada->day, &novo->retirada->month, &novo->retirada->year);

    printf ("Digite a data da devolucao (DD MM AAAA): ");
    scanf ("%d %d %d", &novo->devolucao->day, &novo->devolucao->month, &novo->devolucao->year);

    if (listaVeiculos == NULL)
    {
        printf ("Nao existem veiculos cadastrados.\n");
    }
    else
    {
        imprimeVeiculosDisponiveis (listaVeiculos);
        do
        {
            printf ("Digite a placa do veiculo desejado: ");
            scanf ("%s", placaLocal);
            novo->veiculo = realizaLocacao (placaLocal, listaVeiculos);
        } while (novo->veiculo == NULL);
    }
}

Locacao *incluiLocacao (Locacao *listaLocacao, Cliente *listaClientes, Veiculo *listaVeiculos)
{
    Locacao *novo = (Locacao*)malloc(sizeof(Locacao));
    novo->retirada = malloc(sizeof(int)*3);
    novo->devolucao = malloc(sizeof(int)*3);
    leDadosLocacao (listaLocacao, novo, listaClientes, listaVeiculos);
    novo->prox = listaLocacao;

    return novo;
}

void listarLocacoes(Locacao *listaLocacao){
    Locacao *p;
    for (p = listaLocacao; p != NULL; p = p->prox)
    {
            printf ("Cliente: %s ||", p->cliente->nome);
            printf (" Veiculo: %s ||", p->veiculo->placa);
            printf (" valor pago: %.2f ||", p->valorPago);
    }
}
