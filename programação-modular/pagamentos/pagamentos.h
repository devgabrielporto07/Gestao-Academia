#ifndef PAGAMENTOS_H
#define PAGAMENTOS_H

typedef struct {
    int id;
    int id_aluno;
    int id_plano;
    double valor;
    int forma;   // 1-Dinheiro  2-Pix  3-Cartao
    int pago;    // 1 = pago, 0 = pendente
} Pagamento;

void registrar_pagamento(void);
void listar_pagamentos(void);
void menu_pagamentos(void);

#endif