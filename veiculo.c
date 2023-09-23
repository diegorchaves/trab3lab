#include <stdio.h>
#include <stdlib.h>
#include "veiculo.h"
#include "data.h"

Veiculo* criaVeiculoLista(void){
    return NULL;

}

void leDadosVeiculo(Veiculo* novo){
    printf("Digite a placa do veiculo: \n");
    scanf(" %s", novo->placa);
    printf("Digite a marca do veiculo: \n");
    scanf(" %s", novo->marca);
    printf("Digite a modelo do veiculo: \n");
    scanf(" %s", novo->modelo);
    printf("Digite a ano de Fabricacao do veiculo: \n");
    scanf(" %d", &novo->anoFabricacao);
    printf("Digite a kilometragem do veiculo: \n");
    scanf(" %f", &novo->kilometragem);
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
        printf(" modelo: %s || disponivel? %d \n", p->modelo, p->disponivel);
    }
}

// void imprimeVeiculoDisponiveis(Veiculo* veiculo, Date retirada, Date devolucao){
//     // Veiculo* p;

//     // for(p = veiculo; p != NULL; p = p->prox){
//     //    if(p->disponivel != 0){
//     //    }
//     // }
// }