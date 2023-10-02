#include <stdlib.h>
#include <stdio.h>
#include "veiculo.h"
#include "cliente.h"
#include "locacao.h"
#include "datas.h"
#include "menu.h"

int main ()
{
    int index;
    Veiculo *lstVeiculos = NULL;
    Cliente *lstClientes = NULL;
    Locacao *lstLocacoes = NULL;

    do
    {
        menu();
        scanf("%d", &index);
        leOpcaoMenu(index, &lstVeiculos, &lstClientes, &lstLocacoes);
    } while(1);

}
