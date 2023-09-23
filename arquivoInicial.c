#include <stdio.h>
#include <stdlib.h>

typedef struct veiculo
{
    char placa[8];
    char marca[15];
    char modelo[20];
    int anoFabricacao;
    int kmAtual;
    float valorDiaria;
    int disponibilidade;
} Veiculo;

typedef struct cliente
{
    int cnh;
    char nome[30];
    int telefone;
} Cliente;

typedef struct locacao
{
    Cliente *cliente;
    Veiculo *veiculo;
    int diaRetirada;
    int diaDevolucao;
    int valorPago;
} Locacao;

Veiculo *incluiVeiculo (Veiculo *veiculo)
{
    
}