#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"
#include "data.h"

Veiculo* criaVeiculoLista(void){
    return NULL;

}

void leDadosVeiculo(Veiculo* novo){
    printf("Digite a marca do veiculo: \n");
    scanf("%s", novo->marca);
    printf("Digite a modelo do veiculo: \n");
    scanf(" %s", novo->modelo);
    printf("Digite a placa do veiculo: \n");
    scanf("%s", novo->placa);
    // printf("Digite a ano de Fabricacao do veiculo: \n");
    // scanf(" %d", &novo->anoFabricacao);
    // printf("Digite a kilometragem do veiculo: \n");
    // scanf(" %f", &novo->kilometragem);
    printf("Digite o valor da diaria do veiculo: \n");
    scanf(" %f", &novo->diaria);
    printf("Disponibilidade do veiculo: \n");
    scanf(" %d", &novo->disponivel);
}

Veiculo* incluiVeiculo(Veiculo* veiculo)
{
    Veiculo* novo = (Veiculo*) malloc(sizeof(Veiculo));
    leDadosVeiculo(novo);
    novo->prox = veiculo;
    novo->id = (veiculo != NULL) ?  veiculo->id + 1 : 0;

    return novo;
}

void imprimeVeiculoTodos(Veiculo* veiculo){
    Veiculo* p;

    for(p = veiculo; p != NULL; p = p->prox){
        printf(" modelo: %s || Placa %s || marca %s \n", p->modelo, p->placa, p->marca);
    }
}

void imprimeVeiculoDisponiveis(Veiculo* veiculoLista){
    Veiculo* p;

    for(p = veiculoLista; p != NULL; p = p->prox){
        if(p->disponivel == 1){ //VERIFICA SE N ESTA LOCADO
            printf("Veiculo Diponivel: %s , PLACA: %s \n", p->modelo, p->placa);
        }
    }
}

Veiculo *procuraVeiculo(char placa[8], Veiculo *veiculoLista)
{
    Veiculo *p;

    for (p = veiculoLista; p != NULL; p = p->prox)
    {
        if (strcmp(placa, p->placa) == 0 && p->disponivel == 1)
        {
            return p;
        }
    }

    return NULL;
}