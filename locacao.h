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

void imprimeLocacoesAtivas (Locacao *lstLocacoes, struct data *dataLocal);

void realizaDevolucao (char *placaLocal, Locacao **lstLocacoes, struct data *dataLocal);

void leDadosDevolucao (Locacao *lstLocacoes);

void calculaFaturamento (Locacao *lstLocacoes);

void historico(Locacao *lstLocacoes);
