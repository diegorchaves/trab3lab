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

Cliente *procuraCliente(char nome[30], Cliente *clienteLista);

void leDadosLocacao(Locacao *novo, Cliente *clienteLista, Veiculo *veiculoLista);

Locacao *incluiLocacao(Locacao *locacao, Cliente *clienteLista, Veiculo *veiculoLista);