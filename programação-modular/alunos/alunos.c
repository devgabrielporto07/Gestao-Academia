// Alfredo escreve aqui:
#include <stdio.h>
#include <string.h>
#include "alunos.h"
//vetor onde os alunos ficam salvos e o contador de cadastros
Aluno alunos[100];
int total = 0; //conta quantos alunos existem no vetor 

int aluno_existe_e_ativo(int id_busca) {
    for (int i = 0; i < total; i++) {
        if (alunos[i].id == id_busca && alunos[i].ativo == 1) {
                return 1; //esta ativo e foi achado
        }
    }
    return 0; //caso nao exista ou se foi removido 
}
void cadastrar_aluno() {
    // verifica se cabe mais gente no vetor
    if (total >= 100) {
        printf("Erro: limite de alunos atingido\n");
        return;
    }
    
    printf("\n--- NOVO CADASTRO ---\n");
    //nome
    printf("Digite seu nome: ");
    fgets(alunos[total].nome, 100, stdin); 
    
    if (alunos[total].nome[0] == '\n') {
        printf("Erro: O nome nao pode estar vazio\n");
        return; //cancela o cadastro e volta para o menu
    }
    //cpf
    printf("Digite seu cpf: ");
    fgets(alunos[total].cpf, 15, stdin);
    
    if (alunos[total].cpf[0] == '\n') {
        printf("Erro: o cpf nao pode ficar vazio\n");
        return; // para e volta pro menu
    }
    for (int i = 0; i < total; i++ ){
        if (alunos[i].ativo == 1 && strcmp(alunos[i].cpf, alunos[total].cpf) == 0) {
            printf("Erro: CPF ja cadastrado\n");
            return; //para e volta pro menu
        }
    }

    printf("Digite seu telefone: ");
    fgets(alunos[total].telefone, 20, stdin);

    alunos[total].id = total +1;
    alunos[total].ativo = 1;
    total++;

    printf("Aluno cadastrado com sucesso! ID gerado: %d\n", alunos[total - 1].id);
}
void listar_alunos() {
    printf("\n--- LISTA DE ALUNOS ---\n");
    int encontrou = 1;

    for (int i = 0; i < total; i++){
        if (alunos[i].ativo == 1){
            printf("ID: %d\n", alunos[i].id);
            printf("Nome: %s", alunos[i].nome);
            printf("CPF: %s", alunos[i].cpf);
            printf("\nTelefone: %s", alunos[i].telefone);
            printf("-----------------------\n");
        }
    }
    if(encontrou == 1) {
        printf("Nenhum aluno ativo cadastrado no momento. \n");
    }
}
void buscar_aluno(){
    int opcao_busca;
    printf("\n--- BUSCAR ALUNO ---\n");
    printf("1 - Buscar por ID\n");
    printf("2 - Buscar por CPF\n");
    printf("Escolha: ");
    scanf("%d", &opcao_busca);
    getchar(); //limpa o enter do scanf

    if (opcao_busca == 1) {
        int id_busca;
        printf("Digite o ID do aluno: ");
        scanf("%d", &id_busca);
        getchar();

        for (int i = 0; i < total; i++) {
            if (alunos[i].ativo == 1 && alunos[i].id == id_busca) {
                printf("\n--- Aluno Encontrado ---\n");
                printf("ID: %d\n", alunos[i].id);
                printf("Nome: %s", alunos[i].nome);
                printf("CPF: %s", alunos[i].cpf);
                printf("Telefone: %s", alunos[i].telefone);
                return; //caso ache ele sai da funcao
            }
        }
    } else if (opcao_busca == 2) {
        char cpf_busca[15];
        printf("Digite o CPF do aluno: ");
        fgets(cpf_busca, 15, stdin);

        for (int i = 0; i < total; i++) {
            if (alunos[i].ativo == 1 && strcmp(alunos[i].cpf, cpf_busca) == 0) {
                printf("ID: %d\n", alunos[i].id);
                printf("Nome : %s", alunos[i].nome);
                printf("CPF: %s", alunos[i].cpf);
                printf("Telefone: %s", alunos[i].telefone);
                return; //achou sai
            }
        }
    } else {
        printf("Opcao invalida!\n");
        return;
    }
    printf("Aluno nao enncontrado\n");
}    
void remover_aluno() {
    int id_busca;
    printf("\n--- REMOVER ALUNO ---\n");
    printf("Digite o ID do aluno que deseja remover: ");
    scanf("%d", &id_busca);
    getchar(); // Limpa o Enter do teclado

    for (int i = 0; i < total; i++) {
        if (alunos[i].ativo == 1 && alunos[i].id == id_busca) {
            alunos[i].ativo = 0; // Desativa o aluno (exclusao logica)
            printf("Aluno removido com sucesso!\n");
            return; // Encerra a funcao assim que remove
        }
    }

    printf("Aluno nao encontrado!\n");
}
void editar_aluno() {
    int id_busca;
    printf("\n--- EDITAR ALUNO ---\n");
    printf("Digite o ID do aluno que deseja editar: ");
    scanf("%d", &id_busca);
    getchar(); // Limpa o Enter

    for (int i = 0; i < total; i++) {
        if (alunos[i].ativo == 1 && alunos[i].id == id_busca) {
            char novo_nome[100];
            char novo_cpf[15];

            // 1. Lê o novo nome em uma variável temporária para validar antes de salvar
            printf("Digite o novo nome: ");
            fgets(novo_nome, 100, stdin);
            if (novo_nome[0] == '\n') {
                printf("Erro: O nome nao pode ficar vazio!\n");
                return;
            }

            // 2. Lê o novo CPF e verifica se está vazio
            printf("Digite o novo CPF: ");
            fgets(novo_cpf, 15, stdin);
            if (novo_cpf[0] == '\n') {
                printf("Erro: O CPF nao pode ficar vazio!\n");
                return;
            }

            // 3. Verifica se o novo CPF já pertence a OUTRO aluno ativo (j != i)
            for (int j = 0; j < total; j++) {
                if (j != i && alunos[j].ativo == 1 && strcmp(alunos[j].cpf, novo_cpf) == 0) {
                    printf("Erro: Este CPF ja esta cadastrado em outro aluno!\n");
                    return;
                }
            }

            // 4. Se passou nas validações, copia os textos novos para a struct e lê o telefone
            strcpy(alunos[i].nome, novo_nome);
            strcpy(alunos[i].cpf, novo_cpf);

            printf("Digite o novo telefone: ");
            fgets(alunos[i].telefone, 20, stdin);

            printf("Dados do aluno atualizados com sucesso!\n");
            return;
        }
    }

    printf("Aluno nao encontrado!\n");
}

void menu_alunos() {
    int opcao;

    do {
        printf("\n=== GESTAO DE ALUNOS ===\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar aluno\n");
        printf("4 - Editar aluno\n");
        printf("5 - Remover aluno\n");
        printf("0 - Ir para Planos\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa enter

        switch (opcao) {
            case 1:
                cadastrar_aluno();
                break;
            case 2:
                listar_alunos();
                break;
            case 3:
                buscar_aluno();
                break;
            case 4:
                editar_aluno();
                break;
            case 5:
                remover_aluno();
                break;
            case 0:
                printf("Saindo da gestao de alunos...\n");
                puts ("Entrando em planos...");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
}