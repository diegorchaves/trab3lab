#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"
#include "locacao.h"
#include "cliente.h"
#include "datas.h"

/* Locacao *liberaLocacao (Locacao *listaLocacoes, Locacao *excluir)
{
    Locacao *p = listaLocacoes;
    Locacao *ant = NULL;
    while (p != NULL && p != excluir)
    {
        ant = p;
        p = p->prox;
    }

    if (p == excluir)
    {
        if (ant == NULL)
        {
            listaLocacoes = p->prox;
        }
        else
        {
            ant->prox = p->prox;
        }
        free (p);
    }
    

    return listaLocacoes;
} */

/* void devolveVeiculo (Veiculo *listaVeiculos, struct cliente *listaClientes, Locacao *listaLocacoes)
{
    Cliente *p;
    int devolver;
    float kmAtual;
    char nomeLocal[30];
    printf ("Locacoes ativas: \n\n");
    listarLocacoes (listaLocacoes);
    getchar ();
    do
    {
        printf ("Informe o nome do cliente: ");
        fgets (nomeLocal, sizeof(nomeLocal), stdin);
        nomeLocal[strcspn(nomeLocal, "\n")] = '\0';
        p = procuraCliente (nomeLocal, listaClientes);
        if (p == NULL)
        {
            printf ("Cliente nao encontrado, verifique o nome.\n");
        }
    } while (p == NULL);

    Locacao *l = listaLocacoes;
    while (l != NULL && l->cliente != p)
    {
        l = l->prox;
    }
    if (l == NULL)
    {
        printf ("O cliente %s nao tem locacao ativa.\n", nomeLocal);
        return;
    }

    printf ("O cliente esta com a seguinte locacao ativa: \n");
    listarLocacoes (l);
    printf ("Deseja devolver o carro (1 para sim, 0 para nao): ");
    scanf ("%d", &devolver);
    if (devolver)
    {
        printf ("Digite a quilometragem atual do carro: ");
        scanf ("%f", &kmAtual);
        l->veiculo->kilometragem = kmAtual;
        l->veiculo->disponivel = 1;
        listaLocacoes = liberaLocacao (listaLocacoes, l);
    }
} */

void realizaDevolucao (char *placaLocal, Locacao **listaLocacao)
{
    float kmLocal;
    Locacao *p;
    Locacao *ant = NULL;

    for (p = *listaLocacao; p != NULL; p = p->prox)
    {
        if (p->veiculo->disponivel == 0 && strcmp (placaLocal, p->veiculo->placa) == 0)
        {
            p->veiculo->disponivel = 1;
            printf ("Digite a quilometragem atual: ");
            scanf ("%f", &kmLocal);
            p->veiculo->kilometragem = kmLocal;
            return;
        }
    }
    printf ("Placa nao encontrada, por favor verifique.\n");
}

void devolveVeiculo (Locacao *listaLocacao)
{
    if (listaLocacao == NULL)
    {
        printf ("Nao existem locacoes.\n");
        return;
    }
    listarLocacoesAtivas (listaLocacao);
    char placaLocal[8];
    Locacao *locacaoLocal;
    do
    {
        printf ("Digite a placa do veiculo que deseja devolver: ");
        scanf ("%s", placaLocal);
        realizaDevolucao (placaLocal, &listaLocacao);
    } while (locacaoLocal == NULL);
}

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
        nomeLocal[strcspn(nomeLocal, "\n")] = '\0';
        novo->cliente = procuraCliente (nomeLocal, listaClientes);
        if (novo->cliente == NULL)
        {
            printf ("Cliente nao encontrado, verifique o nome.\n");
        }
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
            if (novo->veiculo == NULL)
            {
                printf ("Veiculo nao encontrado, verifique a placa.\n");
            }
        } while (novo->veiculo == NULL);
    }

    novo->valorPago = novo->veiculo->diaria * daysBetweenDates(*novo->retirada, *novo->devolucao);
}

Locacao *incluiLocacao (Locacao *listaLocacao, Cliente *listaClientes, Veiculo *listaVeiculos)
{
    Locacao *novo = (Locacao*)malloc(sizeof(Locacao));
    novo->retirada = (Date*)malloc(sizeof(int)*3);
    novo->devolucao = (Date*)malloc(sizeof(int)*3);
    leDadosLocacao (listaLocacao, novo, listaClientes, listaVeiculos);
    novo->prox = listaLocacao;

    return novo;
}

void listarLocacoesAtivas (Locacao *listaLocacao){
    Locacao *p = listaLocacao;
    Date *dataLocal = (Date*)malloc(sizeof(Date));
    if (p == NULL)
    {
        printf ("Nao existem locacoes ativas.\n");
    }
    else
    {
        printf ("Digite a data atual (DD MM AAAA): ");
        scanf ("%d %d %d", &dataLocal->day, &dataLocal->month, &dataLocal->year);
        while (p != NULL && (daysBetweenDates (*dataLocal, *p->devolucao) >= 0) && p->veiculo->disponivel == 0)
        {
            printf ("Cliente: %s || ", p->cliente->nome);
            printf ("Veiculo: %s || ", p->veiculo->placa);
            printf ("Valor pago: %.2f\n", p->valorPago);
            p = p->prox;
        }
    }
}
