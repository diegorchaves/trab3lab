#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"
#include "locacao.h"
#include "cliente.h"
#include "datas.h"

void calculaFaturamento (Locacao *lstLocacoes)
{
    float faturamentoMensal = 0;
    Date *mesLocal = (Date*)malloc(sizeof(Date));
    Locacao *p;
    printf ("Digite o mes (MM): ");
    scanf ("%d", &mesLocal->month);
    for (p = lstLocacoes; p != NULL; p = p->prox)
    {
        if (p->retirada->month == mesLocal->month)
        {
            faturamentoMensal += p->valorPago;
        }
    }
    printf ("O faturamento do mes %d foi de %.2f\n", mesLocal->month, faturamentoMensal);
}

void realizaDevolucao (char *placaLocal, Locacao **lstLocacoes, Date *dataLocal)
{
    float kmLocal;
    Locacao *p;
    Locacao *ant = NULL;

    for (p = *lstLocacoes; p != NULL; p = p->prox)
    {
        if (p->veiculo->disponivel == 0 && strcmp (placaLocal, p->veiculo->placa) == 0)
        {
            p->veiculo->disponivel = 1;
            printf ("Digite a quilometragem atual: ");
            scanf ("%f", &kmLocal);
            p->veiculo->kilometragem = kmLocal;
            p->devolucao = dataLocal;
            printf ("Veiculo Devolvido. \n");
            return;
        }
    }
    printf ("Placa nao encontrada, por favor verifique.\n");
}

void leDadosDevolucao (Locacao *lstLocacoes)
{
    if (lstLocacoes == NULL)
    {
        printf ("Nao existem locacoes.\n");
        return;
    }

    Date *dataLocal = pedeData(dataLocal);
    imprimeLocacoesAtivas (lstLocacoes, dataLocal);

    char placaLocal[8];

    printf ("Digite a placa do veiculo que deseja devolver: ");
    scanf ("%s", placaLocal);
    realizaDevolucao (placaLocal, &lstLocacoes, dataLocal);
}

Veiculo *realizaLocacao (char *placaLocal, Veiculo *lstVeiculos)
{
    Veiculo *p;
    for (p = lstVeiculos; p != NULL; p = p->prox)
    {
        if (p->disponivel == 1 && strcmp (placaLocal, p->placa) == 0)
        {
            p->disponivel = 0;
            return p;
        }
    }
    return NULL;
}

int leDadosLocacao (Locacao *lstLocacoes, Locacao *novo, Cliente *lstClientes, Veiculo *lstVeiculos)
{
    char nomeLocal[30];
    char placaLocal[8];

    getchar ();
    do
    {
        printf ("Digite o nome do cliente: ");
        fgets (nomeLocal, sizeof(nomeLocal), stdin);
        nomeLocal[strcspn(nomeLocal, "\n")] = '\0';
        novo->cliente = procuraCliente (nomeLocal, lstClientes);
        if (novo->cliente == NULL)
        {
            printf ("Cliente nao encontrado, verifique o nome.\n");
        }
    } while (novo->cliente == NULL);

    printf ("Digite a data de hoje (DD MM AAAA): ");
    scanf ("%d %d %d", &novo->retirada->day, &novo->retirada->month, &novo->retirada->year);

    printf ("Digite a data da devolucao (DD MM AAAA): ");
    scanf ("%d %d %d", &novo->devolucao->day, &novo->devolucao->month, &novo->devolucao->year);


    imprimeVeiculosDisponiveis (lstVeiculos);

    do
    {
        printf ("Digite a placa do veiculo desejado ou sair: ");
        scanf ("%s", placaLocal);
        if(!strcmp(placaLocal, "sair")){
            free(novo->retirada);
            free(novo->devolucao);
            free(novo);
            return 0;
        }
        novo->veiculo = realizaLocacao (placaLocal, lstVeiculos);
        if (novo->veiculo == NULL)
        {
            printf ("Veiculo nao encontrado, verifique a placa.\n");
        }
    } while (novo->veiculo == NULL);
    

    novo->valorPago = novo->veiculo->diaria * daysBetweenDates (*novo->retirada, *novo->devolucao);
    return 1;
}

Locacao *incluiLocacao (Locacao *lstLocacoes, Cliente *lstClientes, Veiculo *lstVeiculos)
{

    if(lstClientes != NULL && lstVeiculos != NULL){
        Locacao *novo = (Locacao*)malloc(sizeof(Locacao));
        novo->retirada = (Date*)malloc(sizeof(int)*3);
        novo->devolucao = (Date*)malloc(sizeof(int)*3);
        if(leDadosLocacao (lstLocacoes, novo, lstClientes, lstVeiculos)){
            novo->prox = lstLocacoes;
            return novo;
        }else{
            printf("Saindo...\n");
            return lstLocacoes;
        }
    }
    
    printf("Listas vazias\n");
    return lstLocacoes;
}

void imprimeLocacoesAtivas (Locacao *lstLocacoes, Date *dataLocal)
{
    Locacao *p = lstLocacoes;
    
    if (p == NULL)
    {
        printf ("Nao existem locacoes ativas.\n");
    }
    else
    { 
        while (p != NULL && (daysBetweenDates (*dataLocal, *p->devolucao) > 0) && p->veiculo->disponivel == 0)
        {
            printf ("Cliente: %s || ", p->cliente->nome);
            printf ("Veiculo: %s || ", p->veiculo->placa);
            printf ("Valor pago: %.2f\n", p->valorPago);
            p = p->prox;
        }
    }
}

void historico(Locacao *lstLocacoes){
    int cnhLocal;
    int i = 0;
    Locacao *p = lstLocacoes;

    if (p == NULL)
    {
        printf ("Nao existem locacoes cadastradas.\n");
    }
    else
    {   
        
        printf ("Digite a CNH do cliente: ");
        scanf(" %d", &cnhLocal);

        while (p != NULL)
        {  
            if(p->cliente->cnh == cnhLocal){
                printf ("Cliente: %s || ", p->cliente->nome);
                printf ("Veiculo: %s || ", p->veiculo->placa);
                printf ("Valor pago: %.2f\n", p->valorPago);
                i++;
            }
            p = p->prox;
        }

        if(i == 0){
            printf ("Sem historico de locacao!\n");
        }
    }
}
