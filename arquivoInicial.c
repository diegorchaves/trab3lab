#include <stdio.h>
#include <stdlib.h>

struct veiculo{
    char placa[8];
    char marca[15];
    char modelo[20];
    int anoFabricacao;
    float kilometragem;
    float valor;
    int disponivel;
    struct veiculo* prox;
};
typedef struct veiculo Veiculo;

struct cliente{
    int cnh;
    char nome[30];
    int telefone;
    struct cliente* prox;
};
typedef struct cliente Cliente;

struct locacao{
    Cliente* cliente;
    Veiculo* veiculo;
    int retirada;
    int devolucao;
    float valorPago;
    struct locacao* prox;
};
typedef struct locacao Locacao;

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
    scanf(" %d", novo->anoFabricacao);
    printf("Digite a kilometragem do veiculo: \n");
    scanf(" %f", novo->kilometragem);
    printf("Digite o valor da diaria do veiculo: \n");
    scanf(" %f", novo->valor);
    printf("Disponibilidade do veiculo: \n");
    scanf(" %d", novo->disponivel);
}

Veiculo* incluiVeiculo(Veiculo* veiculo)
{
    Veiculo* novo = (Veiculo*) malloc(sizeof(Veiculo));
    leDadosVeiculo(novo);
    novo->prox = veiculo;

    return novo;
}

void imprimeVeiculo(Veiculo* veiculo){
    Veiculo* p;

    for(p = veiculo; p != NULL; p = p->prox){
        printf(" modelo: %s || disponivel? %d \n", p->modelo, p->disponivel);
    }
}

int main(){

    Veiculo* listaVeiculo;

    listaVeiculo = criaVeiculoLista();

    listaVeiculo = incluiVeiculo(listaVeiculo);
    //listaVeiculo = incluiVeiculo(listaVeiculo);

    //imprimeVeiculo(listaVeiculo);

    return 0;
}