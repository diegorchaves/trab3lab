#include <stdio.h>
#include <stdlib.h>

struct veiculo{
    int id;
    char placa[8];
    char marca[15];
    char modelo[20];
    int anoFabricacao;
    float kilometragem;
    float diaria;
    int disponivel;
    struct veiculo* prox;
};
typedef struct veiculo Veiculo;

Veiculo* criaVeiculoLista(void);

void leDadosVeiculo(Veiculo* novo);

Veiculo* incluiVeiculo(Veiculo* veiculo);

void imprimeVeiculoTodos(Veiculo* veiculo);

// void imprimeVeiculoDisponiveis(Veiculo* veiculo, Date retirada, Date devolucao);