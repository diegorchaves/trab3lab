#include <stdlib.h>
#include <stdio.h>
#include "datas.h"
#include "veiculo.h"
#include "cliente.h"
#include "locacao.h"

void menu ()
{
    printf("+-----------------------------+-");
    printf("------------------------------------+\n");
    printf("|1 - Adicionar Veiculo        | ");
    printf("7 - Listar Veiculos                 |\n");
    printf("|2 - Adicionar Clientes       | ");
    printf("8 - Listar Clientes                 |\n");
    printf("|3 - Adicionar Locacao        | ");
    printf("9 - (R1)Listar Locacoes ativas      |\n");
    printf("|4 - Devolver Veiculo         | ");
    printf("10 - (R2)Historico Locacoes Cliente |\n");
    printf("|5 - (R3)Faturamento mes      | ");
    printf("11 - (R4)Veiculos mais rodados      |\n");
    printf("|6 - (R5)Veiculos Disponiveis | ");
    printf("12 - Sair                           |\n");
    printf("+-----------------------------+-");
    printf("------------------------------------+\n");
}

void leOpcaoMenu (int index, Veiculo **lstVeiculos, Cliente **lstClientes, Locacao **lstLocacoes)
{
    Date *dataLocal = NULL;
    switch (index)
    {
        case 1:
            *lstVeiculos = incluiVeiculo (*lstVeiculos);
            break;
        case 2:
            *lstClientes = incluiCliente (*lstClientes);
            break;
        case 3:
            *lstLocacoes = incluiLocacao (*lstLocacoes, *lstClientes, *lstVeiculos);
            break;
        case 4:
            leDadosDevolucao (*lstLocacoes);
            break;
        case 5:
            calculaFaturamento (*lstLocacoes);
            break;
        case 6:
            imprimeVeiculosDisponiveis (*lstVeiculos);
            break;
        case 7:
            imprimeVeiculos (*lstVeiculos);
            break;
        case 8:
            imprimeClientes (*lstClientes);
            break;
        case 9:
            dataLocal = pedeData (dataLocal);
            imprimeLocacoesAtivas (*lstLocacoes, dataLocal);
            break;
        case 10:
            historico (*lstLocacoes);
            break;
        case 11:
            maisRodados (*lstVeiculos);
            break;
        case 12:
            printf("Encerrando programa...\n");
            exit(1);
        default:
            break;
    }
}
