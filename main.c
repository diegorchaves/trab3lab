#include <stdlib.h>
#include "veiculo.h"
#include "cliente.h"
#include "locacao.h"

int main ()
{
    Veiculo *listaVeiculos = NULL;
    Cliente *listaClientes = NULL;
    Locacao *listaLocacoes = NULL;

    listaVeiculos = incluiVeiculos (listaVeiculos);
    listaClientes = incluiClientes (listaClientes);
    listaLocacoes = incluiLocacao (listaLocacoes, listaClientes, listaVeiculos);
}