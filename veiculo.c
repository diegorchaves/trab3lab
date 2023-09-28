#include <stdio.h>
#include <stdlib.h>
#include "veiculo.h"

void imprimeVeiculosDisponiveis (Veiculo *listaVeiculos)
{
    Veiculo *p;
    for (p = listaVeiculos; p != NULL; p = p->prox)
    {
        if (p->disponivel)
        {
            printf ("Placa: %s ||", p->placa);
            printf (" Marca: %s ||", p->marca);
            printf (" Modelo: %s ||", p->modelo);
            printf (" Ano de fabricacao: %d ||", p->anoFabricacao);
            printf (" Quilometragem: %.2f ||", p->kilometragem);
            printf (" Valor diaria: %.2f\n", p->diaria);
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

Veiculo *incluiVeiculos (Veiculo *listaVeiculos)
{
    Veiculo *novo = (Veiculo*)malloc(sizeof(Veiculo));
    if (novo == NULL)
    {
        printf ("Erro ao alocar veiculo.\n");
        exit (1);
    }
    novo->prox = listaVeiculos;
    leDadosVeiculo (novo);
    return novo;
}

void listarVeiculos(Veiculo *listaVeiculos){
    Veiculo *p;
    for (p = listaVeiculos; p != NULL; p = p->prox)
    {
            printf ("Placa: %s ||", p->placa);
            printf (" Marca: %s ||", p->marca);
            printf (" Modelo: %s ||", p->modelo);
            printf (" Ano de fabricacao: %d ||", p->anoFabricacao);
            printf (" Quilometragem: %.2f ||", p->kilometragem);
            printf (" Valor diaria: %.2f\n", p->diaria);
    }
}