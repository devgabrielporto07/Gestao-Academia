#include <stdio.h>
#include "planos/planos.h"
#include "alunos/alunos.h"
// ponto de entrada do programa geral (chamando todas as funções definidas nos arquivos .h e a logica nos arquivos .c (implementando as funções))
int main(void) {
    menu_alunos(); // abre o menu de alunos; ele volta ao main quando o usuario escolhe 0 
    // no geral chamou menu_alunos (); sem a verificação do if igual a do planos porque a maioria das funções foram definidas como void ou seja não vai retornar nenhum tipo de valor
    // ja na função planos tem o return 1; que vai retornar algo por isso que foi definida como int e armazenada dentro de resultados

    int resultado = planos(); // depois do menu de alunos, executa o modulo de planos
    if (resultado != 0) { // testar o valor armazenado verifica o numero guardado, 0 é falso vai prosseguir até a próxima função a ser chamada pela a main
        puts("A funcao planos sinalizou um erro."); // devolve um valor que vocês combinaram representar erro, com return 1
        return resultado; // encerra o programa se planos indicar erro
    }

    return 0; // termina a main
}