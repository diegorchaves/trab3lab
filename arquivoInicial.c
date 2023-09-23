#include <stdio.h>
#include <stdlib.h>
#include "data.h"

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
    Date retirada;
    Date devolucao;
    float valorPago;
    struct locacao* prox;
};
typedef struct locacao Locacao;

//Funcoes veiculo
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

void imprimeVeiculoDisponiveis(Veiculo* veiculo){
    Veiculo* p;

    for(p = veiculo; p != NULL; p = p->prox){
        printf(" modelo: %s || disponivel? %d \n", p->modelo, p->disponivel);
    }
}

//Funcoes Cliente
Cliente* criaClienteLista(void){
    return NULL;
}

void leDadosCliente(Cliente* novo){
    printf("Digite a cnh do Cliente: \n");
    scanf(" %d", &novo->cnh);
    getchar();
    printf("Digite o nome do Cliente: \n");
    fgets(novo->nome, sizeof(novo->nome), stdin);
    printf("Digite o telefone do Cliente: \n");
    scanf(" %d", &novo->telefone);
}

Cliente* incluiCliente(Cliente* cliente)
{
    Cliente* novo = (Cliente*) malloc(sizeof(Cliente));
    leDadosCliente(novo);
    novo->prox = cliente;

    return novo;
}

void imprimeCliente(Cliente* cliente){
    Cliente* p;

    for(p = cliente; p != NULL; p = p->prox){
        printf(" cnh: %d || nome: %s || telefone: %d \n", p->cnh, p->nome, p->telefone);
    }
}

//Funcoes locacoes

Cliente* procuraCliente(char nome[30], Cliente* clienteLista){
    Cliente* p;

    for(p = clienteLista; p =! NULL; p = p->prox){
        if(strcmp(nome, p->nome) == 0){
            return p;
        }
    }

    return NULL;
}

Locacao* criaLocacaoLista(void){
    return NULL;
}

void leDadosLocacao(Locacao* novo, Cliente* clienteLista, Veiculo* veiculoLista){
    char nomeLocal[30];

    do{
        printf("Digite o nome do cliente: ");
        fgets(nomeLocal, sizeof(nomeLocal), stdin);
        novo->cliente = procuraCliente(nomeLocal, clienteLista);
    }while(novo->cliente == NULL);
    
    printf("Digite a data da locacao: ");
    scanf(" %d %d %d", &novo->retirada.day, &novo->retirada.month, &novo->retirada.year);

    printf("Digite a data da devolucao: ");
    scanf(" %d %d %d", &novo->devolucao.day, &novo->devolucao.month, &novo->devolucao.year);

    imprimeVeiculoDisponiveis(veiculosLista)

}

Locacao* incluiLocacao(Locacao* locacao, Cliente* clienteLista, Veiculo* veiculoLista)
{
    Locacao* novo = (Locacao*) malloc(sizeof(Locacao));
    leDadosLocacao(novo, clienteLista, veiculoLista);
    novo->prox = locacao;

    return novo;
}


int main(){


    return 0;
}