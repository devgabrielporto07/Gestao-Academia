// Kaynan escreve aqui:
#include <stdio.h> // entradas e saidas: printf scanf
#include "frequencia.h" // importa o header do módulo
#define MAX_ENTRADAS 1000 // quantas entradas cabem na memória
// Cada entrada fica na mesma posição das 6 listas .
// Ex.: ids[0], dias[0], meses[0]... juntos formam a primeira entrada.
// static = só este arquivo enxerga (evita conflito de nomes com os outros módulos)
static int ids[MAX_ENTRADAS], dias[MAX_ENTRADAS], meses[MAX_ENTRADAS];
static int anos[MAX_ENTRADAS], horas[MAX_ENTRADAS], minutos[MAX_ENTRADAS];
static int total = 0; // quantas entradas já foram registradas
// Matrícula ativa: SIMULADA por enquanto (alunos 1, 2, 3 e 5 têm; o aluno 4 não tem).
// Quando o módulo de Matrículas ficar pronto, é só trocar o corpo desta função.
static int aluno_tem_matricula(int id_aluno) {
    if (id_aluno == 1 || id_aluno == 2 || id_aluno == 3 || id_aluno == 5) {
        return 1;
    }
    return 0;
}
// Devolve 1 se o aluno já tem entrada nesse dia e 0 se não tem.
static int ja_entrou_no_dia(int id_aluno, int dia, int mes, int ano) {
    int i;
    for (i = 0; i < total; i++) {
        if (ids[i] == id_aluno && dias[i] == dia && meses[i] == mes && anos[i] == ano) {
            return 1;
        }
    }
    return 0;
}
// Registra a entrada de um aluno. Devolve OK ou um código de erro.
int frequencia_registrar(int id_aluno, int dia, int mes, int ano, int hora, int minuto) {
    // dados que não fazem sentido (ou lista cheia)
    if (id_aluno <= 0 || dia < 1 || dia > 31 || mes < 1 || mes > 12 || hora < 0 || hora > 23 || minuto < 0 || minuto > 59 || total >= MAX_ENTRADAS) {
        return ERRO_INVALIDO;
    }
    // regra 1: só registra se o aluno tiver matrícula ativa
    if (aluno_tem_matricula(id_aluno) == 0) {
        return ERRO_REGRA;
    }
    // regra 2: uma entrada por dia por aluno
    if (ja_entrou_no_dia(id_aluno, dia, mes, ano) == 1) {
        return ERRO_DUPLICADO;
    }
    // passou em tudo: guarda a data e a hora da entrada
    ids[total] = id_aluno;
    dias[total] = dia;
    meses[total] = mes;
    anos[total] = ano;
    horas[total] = hora;
    minutos[total] = minuto;
    total++;
    return OK;
}
// Quantos dias o aluno veio no mês. Devolve ERRO_INVALIDO se o id ou o mês forem inválidos.
int frequencia_contar_no_mes(int id_aluno, int mes, int ano) {
    int i, contador = 0;
    if (id_aluno <= 0 || mes < 1 || mes > 12) {
        return ERRO_INVALIDO;
    }
    for (i = 0; i < total; i++) {
        if (ids[i] == id_aluno && meses[i] == mes && anos[i] == ano) {
            contador++; // como só pode 1 entrada por dia, cada entrada = 1 dia
        }
    }
    return contador;
}
// Mostra na tela todas as entradas de um aluno (só para o terminal).
static void listar_entradas(int id_aluno) {
    int i, contador = 0;
    printf("Entradas do aluno %d:\n", id_aluno);
    for (i = 0; i < total; i++) {
        if (ids[i] == id_aluno) {
            // %02d mostra o número com 2 dígitos (07 em vez de 7)
            printf("  %d/%d/%d as %02d:%02d\n", dias[i], meses[i], anos[i], horas[i], minutos[i]);
            contador++;
        }
    }
    if (contador == 0) {
        printf("Nenhuma entrada encontrada.\n");
    }
}
// Logica para o terminal na parte de frequencia da academia
int frequencia(void) {
    int opcao = -1, id = 0, dia = 0, mes = 0, ano = 0, hora = 0, minuto = 0, resultado;
    while (opcao != 0) { // repete o menu até o usuário digitar 0
        printf("\n=== FREQUENCIA ===\n");
        printf("1 - Registrar entrada\n");
        printf("2 - Ver entradas de um aluno\n");
        printf("3 - Quantas vezes o aluno veio no mes\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        if (scanf("%d", &opcao) != 1) { // se não digitou um número, encerra
            printf("Entrada Invalida, digite apenas numeros\n");
            return 1;
        }
        if (opcao == 1) { // REGISTRAR ENTRADA
            printf("ID do aluno: ");
            scanf("%d", &id);
            printf("Data (dia mes ano, ex: 12 11 2026): ");
            scanf("%d %d %d", &dia, &mes, &ano);
            printf("Hora (hora minuto, ex: 18 42): ");
            scanf("%d %d", &hora, &minuto);
            resultado = frequencia_registrar(id, dia, mes, ano, hora, minuto);
            if (resultado == OK) {
                printf("Entrada registrada!\n");
            }
            else if (resultado == ERRO_REGRA) {
                printf("Aluno sem matricula ativa. Entrada nao registrada.\n");
            }
            else if (resultado == ERRO_DUPLICADO) {
                printf("Esse aluno ja entrou nesse dia. Entrada nao registrada.\n");
            }
            else {
                printf("ID, data ou hora invalidos. Entrada nao registrada.\n");
            }
        }
        else if (opcao == 2) { // VER ENTRADAS DE UM ALUNO
            printf("ID do aluno: ");
            scanf("%d", &id);
            listar_entradas(id);
        }
        else if (opcao == 3) { // QUANTOS DIAS O ALUNO VEIO NO MES
            printf("ID do aluno: ");
            scanf("%d", &id);
            printf("Mes e ano (ex: 11 2026): ");
            scanf("%d %d", &mes, &ano);
            resultado = frequencia_contar_no_mes(id, mes, ano);
            if (resultado < 0) {
                printf("ID ou mes invalido.\n");
            }
            else {
                printf("O aluno %d veio %d dia(s) nesse mes.\n", id, resultado);
            }
        }
        else if (opcao != 0) { // qualquer outro número que não está no menu
            printf("Opcao invalida.\n");
        }
    }
    return 0; // final do codigo
}
// =========================================================================
// Funções para integrar com o CSharp (sem printf e sem scanf)
// As entradas ficam nas posições 0 até total-1 das listas.
// =========================================================================

// quantas entradas já foram registradas
int frequencia_total(void) {
    return total;
}

// dados da entrada que está na posição informada (0 se a posição não existe)
int frequencia_id_aluno(int posicao) {
    if (posicao < 0 || posicao >= total) return 0;
    return ids[posicao];
}

int frequencia_dia(int posicao) {
    if (posicao < 0 || posicao >= total) return 0;
    return dias[posicao];
}

int frequencia_mes(int posicao) {
    if (posicao < 0 || posicao >= total) return 0;
    return meses[posicao];
}

int frequencia_ano(int posicao) {
    if (posicao < 0 || posicao >= total) return 0;
    return anos[posicao];
}

int frequencia_hora(int posicao) {
    if (posicao < 0 || posicao >= total) return 0;
    return horas[posicao];
}

int frequencia_minuto(int posicao) {
    if (posicao < 0 || posicao >= total) return 0;
    return minutos[posicao];
}