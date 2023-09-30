#include <stdio.h>
#include <stdlib.h>
#include "veiculo.h"

void imprimeVeiculosDisponiveis (Veiculo *lstVeiculos)
{
    Veiculo *p = lstVeiculos;
    if (p == NULL)
    {
        printf ("Nao existem veiculos disponiveis.\n");
    }
    else
    {
        while (p != NULL && p->disponivel == 1)
        {
            printf ("Placa: %s ||", p->placa);
            printf (" Marca: %s ||", p->marca);
            printf (" Modelo: %s ||", p->modelo);
            printf (" Ano de fabricacao: %d ||", p->anoFabricacao);
            printf (" Quilometragem: %.2f ||", p->kilometragem);
            printf (" Valor diaria: %.2f\n", p->diaria);
            p = p->prox;
        }
    }
}

void leDadosVeiculo (Veiculo *novo)
{
    printf ("Digite a marca do veiculo: \n");
    scanf ("%s", novo->marca);
    printf ("Digite a modelo do veiculo: \n");
    scanf ("%s", novo->modelo);
    printf ("Digite a placa do veiculo: \n");
    scanf ("%s", novo->placa);
    printf ("Digite a ano de fabricacao do veiculo: \n");
    scanf ("%d", &novo->anoFabricacao);
    printf ("Digite a quilometragem do veiculo: \n");
    scanf ("%f", &novo->kilometragem);
    printf ("Digite o valor da diaria do veiculo: \n");
    scanf ("%f", &novo->diaria);
    novo->disponivel = 1;
}

Veiculo *incluiVeiculo (Veiculo *lstVeiculos)
{
    Veiculo *novo = (Veiculo*)malloc(sizeof(Veiculo));
    if (novo == NULL)
    {
        printf ("Erro ao alocar veiculo.\n");
        exit (1);
    }
    novo->prox = lstVeiculos;
    leDadosVeiculo (novo);
    return novo;
}

void imprimeVeiculos (Veiculo *lstVeiculos)
{
    Veiculo *p = lstVeiculos;
    if (p == NULL)
    {
        printf ("Nao existem veiculos cadastrados.\n");
    }
    else
    {
        while (p != NULL)
        {
            printf ("Placa: %s ||", p->placa);
            printf (" Marca: %s ||", p->marca);
            printf (" Modelo: %s ||", p->modelo);
            printf (" Ano de fabricacao: %d ||", p->anoFabricacao);
            printf (" Quilometragem: %.2f ||", p->kilometragem);
            printf (" Valor diaria: %.2f\n", p->diaria);
            p = p->prox;
        }
    }
}

void maisRodados(Veiculo *lstVeiculos){

    Veiculo* top[3] ={NULL, NULL, NULL};

    for(int i = 0; i < 3; i++){
        top[i] = (Veiculo*) malloc(sizeof(Veiculo));
        top[i]->kilometragem = 0;
    }

    if (lstVeiculos == NULL)
    {
        printf ("Nao existem veiculos cadastrados.\n");
    }
    else
    {
        verificaTop(lstVeiculos, top);
        
        Veiculo* p = NULL;
        for(int i = 0; i < 3; i++){
            p = top[i];
            printf ("Placa: %s ||", p->placa);
            printf (" Marca: %s ||", p->marca);
            printf (" Modelo: %s ||", p->modelo);
            printf (" Ano de fabricacao: %d ||", p->anoFabricacao);
            printf (" Quilometragem: %.2f ||", p->kilometragem);
            printf (" Valor diaria: %.2f\n", p->diaria);
        }
                
    }
}

void verificaTop(Veiculo *lstVeiculos, Veiculo* top[3]){

    Veiculo* p = lstVeiculos;

    while (p != NULL)
        {
           if(p->kilometragem > top[0]->kilometragem)
           {    
                top[2] = top[1];
                top[1] = top[0];
                top[0] = p;
                
           }else if(p->kilometragem > top[1]->kilometragem)
           {    
                top[2] = top[1];
                top[1] = p;
           }else if(p->kilometragem > top[2]->kilometragem)
           {
                top[2] = p;
           }
            p = p->prox;
        }
}