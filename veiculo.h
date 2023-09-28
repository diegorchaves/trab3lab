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

Veiculo *incluiVeiculos (Veiculo *listaVeiculos);

int imprimeVeiculosDisponiveis (Veiculo *listaVeiculos);

void leDadosVeiculo (Veiculo *novo);

void listarVeiculos(Veiculo *listaVeiculos);