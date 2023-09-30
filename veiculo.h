typedef struct veiculo
{
    int id;
    char placa[8];
    char marca[15];
    char modelo[20];
    int anoFabricacao;
    float kilometragem;
    float diaria;
    int disponivel;
    struct veiculo *prox;
} Veiculo;

Veiculo *incluiVeiculo (Veiculo *lstVeiculos);

void imprimeVeiculosDisponiveis (Veiculo *lstVeiculos);

void leDadosVeiculo (Veiculo *novo);

void imprimeVeiculos (Veiculo *lstVeiculos);