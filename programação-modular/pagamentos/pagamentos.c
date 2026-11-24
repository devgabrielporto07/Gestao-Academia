#include <stdio.h>
#include "pagamentos.h"
#include "../alunos/alunos.h"
#include "../planos/planos.h"

Pagamento pagamentos[100];
int total_pagamentos = 0;

void menu_pagamentos(void) {
    int opcao;

    do {
        printf("\n=== PAGAMENTOS ===\n");
        printf("1 - Registrar pagamento\n");
        printf("2 - Listar pagamentos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrar_pagamento();
                break;
            case 2:
                listar_pagamentos();
                break;
            case 0:
                printf("Saindo de pagamentos...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

void registrar_pagamento(void) {
    int id_aluno, id_plano;

    if (total_pagamentos >= 100) {
        printf("Erro: limite de pagamentos atingido\n");
        return;
    }

    printf("ID do aluno: ");
    scanf("%d", &id_aluno);
    if (aluno_existe_e_ativo(id_aluno) == 0) {
        printf("Erro: aluno nao encontrado\n");
        return;
    }

    printf("ID do plano (1 a 4): ");
    scanf("%d", &id_plano);
    if (plano_valor(id_plano) == 0) {
        printf("Erro: plano invalido\n");
        return;
    }

    pagamentos[total_pagamentos].id = total_pagamentos + 1;
    pagamentos[total_pagamentos].id_aluno = id_aluno;
    pagamentos[total_pagamentos].id_plano = id_plano;
    pagamentos[total_pagamentos].valor = plano_valor(id_plano);

    printf("Forma (1- Dinheiro 2- Pix 3- Cartao: ");
    scanf("%d", &pagamentos[total_pagamentos].forma);

    printf("Ja foi pago? (1-Sim 0-Nao): ");
    scanf("%d", &pagamentos[total_pagamentos].pago);

    total_pagamentos++;
    printf("Pagamento registrado! Valor: R$ %.2f\n", pagamentos[total_pagamentos - 1].valor);
}

void listar_pagamentos(void) {
    printf("\n--- LISTA DE PAGAMENTOS ---\n");

    if (total_pagamentos == 0) {
        printf("Nenhum pagamento registrado.\n");
        return;
    }

    for (int i = 0; i < total_pagamentos; i++) {
        printf("ID: %d\n", pagamentos[i].id);
        printf("Aluno: %d\n", pagamentos[i].id_aluno);
        printf("Plano: %d\n", pagamentos[i].id_plano);
        printf("Valor: R$ %.2f\n", pagamentos[i].valor);

        if (pagamentos[i].forma == 1) {
            printf("Forma: Dinheiro\n");
        } else if (pagamentos[i].forma == 2) {
            printf("Forma: Pix\n");
        } else {
            printf("Forma: Cartao\n");
        }

        if (pagamentos[i].pago == 1) {
            printf("Situacao: Pago\n");
        } else {
            printf("Situacao: Pendente\n");
        }

        printf("---------------------------\n");
    }
}