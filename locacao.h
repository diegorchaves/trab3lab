typedef struct locacao
{
    struct cliente *cliente;
    struct veiculo *veiculo;
    struct data *retirada;
    struct data *devolucao;
    float valorPago;
    struct locacao *prox;
} Locacao;

Veiculo *realizaLocacao (char *placaLocal, Veiculo *lstVeiculos);

void leDadosLocacao (Locacao *lstLocacoes, Locacao *novo, struct cliente *lstClientes, Veiculo *lstVeiculos);

Locacao *incluiLocacao (Locacao *lstLocacoes, struct cliente *lstClientes, Veiculo *lstVeiculos);

void imprimeLocacoesAtivas (Locacao *lstLocacoes);

void realizaDevolucao (char *placaLocal, Locacao **lstLocacoes);

void leDadosDevolucao (Locacao *lstLocacoes);

void calculaFaturamento (Locacao *lstLocacoes);


