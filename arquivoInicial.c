#include <stdio.h>
#include <stdlib.h>
#include "veiculo.h"
#include "cliente.h"
#include "locacao.h"
#include "data.h"

int main()
{

    Cliente *cliente1;
    Veiculo *veiculo1;
    Locacao *locacao1;

    cliente1 = criaClienteLista();
    veiculo1 = criaVeiculoLista();
    locacao1 = criaLocacaoLista();

    cliente1 = incluiCliente(cliente1);
    // veiculo1 = incluiVeiculo(veiculo1);
    locacao1 = incluiLocacao(locacao1, cliente1, veiculo1);

    imprimeCliente(cliente1);
    imprimeVeiculoTodos(veiculo1);

    return 0;
}