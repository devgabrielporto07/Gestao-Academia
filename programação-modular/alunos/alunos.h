#ifndef ALUNOS_H
#define ALUNOS_H
// Definindo tamanho maximo
typedef struct {
    int id;
    char nome[100];
    char cpf[15];
    char telefone[20];
    int ativo;
} Aluno;
//Função obrigatória para os módulos de matrícula e frequência
//Recebe o ID do aluno e retorna 1 se existir e estiver ativo, ou 0 caso contrário
int aluno_existe_e_ativo(int id);
//Funções internas
void cadastrar_aluno();
void listar_alunos();
void buscar_aluno();
void editar_aluno();
void remover_aluno();
void menu_alunos();

#endif