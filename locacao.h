typedef struct locacao
{
    struct cliente *cliente;
    struct veiculo *veiculo;
    struct data *retirada;
    struct data *devolucao;
    float valorPago;
    struct locacao *prox;
} Locacao;

Veiculo *realizaLocacao (char *placaLocal, Veiculo *listaVeiculos);

Locacao *realizaDevolucao (char *placaLocal, Locacao **listaLocacao);

int leDadosLocacao (Locacao *listaLocacao, Locacao *novo, struct cliente *listaClientes, Veiculo *listaVeiculos);

Locacao *incluiLocacao (Locacao *listaLocacao, struct cliente *listaClientes, Veiculo *listaVeiculos);

void listarLocacoes(Locacao *listaLocacao);

Locacao *devolveLocacao (Locacao *listaLocacao, Veiculo *listaVeiculos);
