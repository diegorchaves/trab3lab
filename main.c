#include <stdlib.h>
#include <stdio.h>
#include "veiculo.h"
#include "cliente.h"
#include "locacao.h"

void menu ()
{
    printf("|---------------------------");
    printf("------------------------------------|\n");
    printf("|1 - Adicionar Veiculo    || ");
    printf("7 - Listar Veiculos                |\n");
    printf("|2 - Adicionar Clientes   || ");
    printf("8 - Listar Clientes                |\n");
    printf("|3 - Adicionar Locacao    || ");
    printf("9 - Listar Locacoes ativas         |\n");
    printf("|4 - Devolver Veiculo     || ");
    printf("10 - Historico Locacoes de Cliente |\n");
    printf("|5 - Faturamento mensal   || ");
    printf("11 - Veiculos mais rodados         |\n");
    printf("|6 - Veiculos Disponiveis || ");
    printf("                                   |\n");
    printf("|---------------------------");
    printf("------------------------------------|\n");
}

void leOpcao (int index, Veiculo **listaVeiculos, Cliente **listaClientes, Locacao **listaLocacoes)
{
    switch (index)
    {
        case 1: 
            *listaVeiculos = incluiVeiculos (*listaVeiculos);
            break;
        case 2: 
            *listaClientes = incluiClientes (*listaClientes);
            break;
        case 3: 
            *listaLocacoes = incluiLocacao (*listaLocacoes, *listaClientes, *listaVeiculos);
            break;
        case 4: 
            devolveVeiculo (*listaLocacoes);
            break;
        case 5: 
            // faturamento(listaVeiculos);
            break;
        case 6: 
            imprimeVeiculosDisponiveis(*listaVeiculos);
            break;
        case 7: 
            listarVeiculos(*listaVeiculos);
            break;
        case 8: 
            listarClientes(*listaClientes);
            break;
        case 9: 
            listarLocacoesAtivas(*listaLocacoes);
            break; 
        case 10: 
            //Historico(listaClientes);
            break;
        case 11: 
            //maisRodados(listaLocacoes);
            break;
        default:
            break;  
    }
}

int main ()
{   
    int index;
    Veiculo *listaVeiculos = NULL;
    Cliente *listaClientes = NULL;
    Locacao *listaLocacoes = NULL;

    do
    {
        menu();
        scanf(" %d", &index);
        leOpcao(index, &listaVeiculos, &listaClientes, &listaLocacoes);
    } while(1);

}