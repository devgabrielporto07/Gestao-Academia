// declaração da função com ifndef 
// .h significa header (cabeçalho)
// nome usado pelo o pre-processador  do C que prepara o codigo antes de compilar #define
// ifndef se PLANOS_H ainda não foi definido marcadores no geral 
// “existe uma função chamada planos; ela não recebe parâmetros e não devolve um valor void planos(void)”
// Juntos, #ifndef e #define evitam que o conteúdo do cabeçalho seja processado mais de uma vez durante a compilação
// #endif Fecha a condição iniciada por #ifndef
// Uma forma de lembrar: o .h é como a lista de serviços de um módulo; ele anuncia que planos() existe. O arquivo planos.c contém o serviço em si
#ifndef PLANOS_H
#define PLANOS_H 

int planos(void);

#endif