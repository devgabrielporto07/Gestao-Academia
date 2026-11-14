// .h significa header
// ifndef e define evitam que este arquivo seja lido mais de uma vez na compilação
#ifndef FREQUENCIA_H
#define FREQUENCIA_H
// Códigos de retorno 0 = deu certo, negativo = deu erro.
#define OK 0
#define ERRO_INVALIDO -1 // id, data ou hora invalidos
#define ERRO_DUPLICADO -3 // o aluno ja entrou nesse dia
#define ERRO_REGRA -5 // aluno sem matricula ativa
// menu de terminal da frequencia (a main chama esta funcao)
int frequencia(void);
// Funções para integrar com CSharp
// registra a entrada do aluno (devolve OK, ERRO_INVALIDO, ERRO_REGRA ou ERRO_DUPLICADO)
int frequencia_registrar(int id_aluno, int dia, int mes, int ano, int hora, int minuto);
// quantos dias o aluno veio no mes (devolve ERRO_INVALIDO se o id ou o mes forem invalidos)
int frequencia_contar_no_mes(int id_aluno, int mes, int ano);
#endif