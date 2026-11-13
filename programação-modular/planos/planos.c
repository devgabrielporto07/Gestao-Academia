// Porto escreve aqui:
#include <stdio.h> // entradas e saidas funções printf scanf
#include <string.h> // importando a biblioteca string para a palavra de inicializacao
#include "planos.h" // programação modular importação do arquivo.h header

// Logica para o terminal na parte de planos da academia
int planos (void) {
    char vermelho_claro[]="\033[1;31m", reset[] = "\033[0m", verde_claro[]="\033[1;32m", amarelo_claro[]="\033[1;33m", roxo_claro[]="\033[1;34m", magenta_claro[]="\033[1;35m", ciano_claro[]="\033[1;36m", branco_claro[]="\033[1;37m";
    char palavra_chave_inicilizacao[7] = "PLANOS", palavra_entrada[7]=""; // começa no espaço 0, no caso vai ler 6 caracteres
    int escolha_id;
    // no geral definição das cores de acordo com tabela ansi, a tabela ansi e os caracters que o computador ler que devolve cor no geral
    printf ("\nOla, seja bem-vindo a parte dos planos para prosseguir digite PLANOS obs(cuidado com maisculas e minusculas): "); // saudação + a palavra chave para inicializar
    if (scanf ("%6s", palavra_entrada) != 1) { // tem que ler 6s para dizer quantos espaços a memória reservou para a leitura ao passar um array nao precisa do & para o endereço da variável, ja representa o endereço do primeiro espaço
        printf ("%sEntrada Invalida, verifique o tipo primitivo digitado e compile novamente o programa%s", vermelho_claro, reset); // verificação do tipo primitivo digitado caso seja compative com definição do tipo primitivo da variável vai retornar 1 e se retornar 0 e porque o valor digitado e diferente da variável definida no escopo global do programa
        return 1;
        }
    else {
        if (strcmp(palavra_chave_inicilizacao, palavra_entrada) == 0) { // retorna 0 quando o conteudo do texto e igual, se voce comparar palavra_chave_inicilizacao == palavra_entrada (ele vai buscar os endereços que são diferentes por mais que você digite igual)
            // srtcmp equivalente ao .equals no java comparar o conteudo da string srtcmp => compara strings e strings em c sao arrays de caracteres
            printf ("%sID | PLANO      | VALOR TOTAL (R$) |  DURACAO | VALOR POR MES |%s\n", branco_claro, reset); // exibição do menu
            printf ("%s(1)| Mensal     |    R$ 100,00     |   1-mes  |     R$100,00  |%s\n", verde_claro, reset); // exibição do menu
            printf ("%s(2)| Trimestral |    R$ 270,00     |   3-mes  |     R$90,00   |%s\n", amarelo_claro, reset); // exibição do menu
            printf ("%s(3)| Semestral  |    R$ 510,00     |   6-mes  |     R$85,00   |%s\n", roxo_claro, reset); // exibição do menu
            printf ("%s(4)| Anual      |    R$ 960,00     |  12-mes  |     R$80,00   |%s\n", magenta_claro, reset); // exibição do menu
            printf ("\nDigite a numeracao do ID para escolher o plano: "); // entrada pedindo o ID de acordo com a tabela
            if (scanf ("%d", &escolha_id) != 1) { // verificação do tipo primitivo digitado caso seja compative com definição do tipo primitivo da variável vai retornar 1 e se retornar 0 e porque o valor digitado e diferente da variável definida no escopo global do programa
                printf ("%sEntrada Invalida, verifique o tipo primitivo digitado e compile novamente o programa%s", vermelho_claro, reset);
                return 1;        
                }
            if (escolha_id < 1 || escolha_id > 4) { // caso o usuario digite um valor maior que os ids da tabela ou menor
                printf ("%sEscolha Invalida, compile novamente o programa%s", vermelho_claro, reset);
                }
            if (escolha_id == 1) { // condicional para cair no ID 1 de acordo com a tabela
                puts ("O plano escolhido foi o:"); // condicional para cair no ID 1 de acordo com a tabela
                printf ("%sID | PLANO      | VALOR TOTAL (R$) |  DURACAO | VALOR POR MES |%s\n", branco_claro, reset);
                printf ("%s(1)| Mensal     |    R$ 100,00     |   1-mes  |     R$100,00  |%s\n", verde_claro, reset);
                printf ("%sPlano cadastrado com SUCESSO!!%s", verde_claro, reset);
                }
            else if (escolha_id == 2) { // condicional para cair no ID 2 de acordo com a tabela
                puts ("O plano escolhido foi o:");
                printf ("%sID | PLANO      | VALOR TOTAL (R$) |  DURACAO | VALOR POR MES |%s\n", branco_claro, reset);
                printf ("%s(2)| Trimestral |    R$ 270,00     |   3-mes  |     R$90,00   |%s\n", amarelo_claro, reset);
                printf ("%sPlano cadastrado com SUCESSO!!%s", verde_claro, reset);
                }
            else if (escolha_id == 3) { // condicional para cair no ID 3 de acordo com a tabela
                puts ("O plano escolhido foi o:");
                printf ("%sID | PLANO      | VALOR TOTAL (R$) |  DURACAO | VALOR POR MES |%s\n", branco_claro, reset);
                printf ("%s(3)| Semestral  |    R$ 510,00     |   6-mes  |     R$85,00   |%s\n", roxo_claro, reset);
                printf ("%sPlano cadastrado com SUCESSO!!%s", verde_claro, reset);
                }
            else if (escolha_id == 4) { // condicional para cair no ID 4 de acordo com a tabela
                puts ("O plano escolhido foi o:");
                printf ("%sID | PLANO      | VALOR TOTAL (R$) |  DURACAO | VALOR POR MES |%s\n", branco_claro, reset);
                printf ("%s(4)| Anual      |    R$ 960,00     |  12-mes  |     R$80,00   |%s\n", magenta_claro, reset);
                printf ("%sPlano cadastrado com SUCESSO!!%s", verde_claro, reset);
                }
            }
        else { // caso o usuario digite outra palavra alem daquela definida para inicalizar a exibição do menu
            printf ("%sEntrada Invalida, verifique a palavra digitada e compile novamente o programa digite: PLANOS%s", vermelho_claro, reset);
        }
    }
    return 0; // indicar o final do codigo
}

// Funções para integrar com CSharp o csharp em si nao ler o printf e o scanf
// Nome do plano pelo ID ("" se o ID não existe).
const char* plano_nome(int id) {
    if (id == 1) return "Mensal";
    if (id == 2) return "Trimestral";
    if (id == 3) return "Semestral";
    if (id == 4) return "Anual";
    return "";
}

// valor total do plano pelo id (0 se o id nao existe)
double plano_valor(int id) {
    if (id == 1) return 100.00;
    if (id == 2) return 270.00;
    if (id == 3) return 510.00;
    if (id == 4) return 960.00;
    return 0;
}

// duracao em meses pelo id (0 se o id nao existe)
int plano_duracao(int id) {
    if (id == 1) return 1;
    if (id == 2) return 3;
    if (id == 3) return 6;
    if (id == 4) return 12;
    return 0;
}