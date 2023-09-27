#include <stdio.h>
#include <stdlib.h>

struct locacao
{
    Cliente *cliente;
    Veiculo *veiculo;
    struct Date *retirada;
    struct Date *devolucao;
    float valorPago;
    struct locacao *prox;
};
typedef struct locacao Locacao;

Locacao *criaLocacaoLista(void);

int estaLocado(Veiculo* veiculo, Locacao* listaLocacao, struct Date *retirada, struct Date *devolucao);

int calculaValorPago(Veiculo* veiculo, struct Date *retirada, struct Date *devolucao);

void leDadosLocacao(Locacao* locacao, Locacao *novo, Cliente *clienteLista, Veiculo *veiculoLista);

Locacao *incluiLocacao(Locacao *locacao, Cliente *clienteLista, Veiculo *veiculoLista);

void imprimeLocacoes(Locacao* locacao);

int achouPlaca (char placaLocal[8], char matrizPlacas[][8], int linhas);