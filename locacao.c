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

    printf("Veiculo nao encontrado...\n");
    return NULL;
}

Locacao *realizaDevolucao (char *placaLocal, Locacao **listaLocacao)
{
    Locacao *p;
    Locacao *ant = NULL;

    for (p = *listaLocacao; p != NULL; p = p->prox)
    {   
        if (p->veiculo->disponivel == 0 && strcmp (placaLocal, p->veiculo->placa) == 0)
        {
            p->veiculo->disponivel = 1;
            if(ant == NULL){
                *listaLocacao = p->prox;
            }else{
                ant->prox = p->prox;
            }
            return p;
        }
        ant = p;
    }

    printf("Veiculo nao encontrado...\n");
    return NULL;
}

int leDadosLocacao (Locacao *listaLocacao, Locacao *novo, Cliente *listaClientes, Veiculo *listaVeiculos)
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
        if(imprimeVeiculosDisponiveis (listaVeiculos)){
            return 0;
        }

        do
        {
            printf ("Digite a placa do veiculo desejado: ");
            scanf ("%s", placaLocal);
            novo->veiculo = realizaLocacao (placaLocal, listaVeiculos);
        } while (novo->veiculo == NULL);
    }

    novo->valorPago = novo->veiculo->diaria * daysBetweenDates(*novo->retirada, *novo->devolucao);

    return 1;
}

Locacao *incluiLocacao (Locacao *listaLocacao, Cliente *listaClientes, Veiculo *listaVeiculos)
{
    Locacao *novo = (Locacao*)malloc(sizeof(Locacao));
    novo->retirada = malloc(sizeof(int)*3);
    novo->devolucao = malloc(sizeof(int)*3);
    if(leDadosLocacao (listaLocacao, novo, listaClientes, listaVeiculos)){
        novo->prox = listaLocacao;
        return novo;
    }
    free(novo->retirada);
    free(novo->devolucao);
    free(novo);
    return listaLocacao;
}

void listarLocacoes(Locacao *listaLocacao)
{
    Locacao *p;

    printf ("\nListando Locacoes...\n");

    if(listaLocacao == NULL){
        printf("Lista vazia... \n");
    }else{
        for (p = listaLocacao; p != NULL; p = p->prox)
        {
            printf ("Cliente: %s ||", p->cliente->nome);
            printf (" Veiculo: %s ||", p->veiculo->placa);
            printf (" valor pago: %.2f ||\n", p->valorPago);
        }
    }
    
}

Locacao *devolveLocacao (Locacao *listaLocacao, Veiculo *listaVeiculos)
{
    listarLocacoes(listaLocacao);

    char placaLocal[8];
    Locacao *locacaoLocal;
    do
    {
        printf ("Digite a placa do veiculo que deseja devolver: ");
        scanf (" %s", placaLocal);
        locacaoLocal = realizaDevolucao(placaLocal, &listaLocacao);
    } while (locacaoLocal == NULL);


    free(locacaoLocal);
    printf ("Veiculo Devolvido...\n");

    return listaLocacao;
}

