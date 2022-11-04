/* Programa para cadastro de pacientes diagnosticados com Covid-19 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct paciente {
    char nome[50];
    char cpf[11];
    char endereco[50];
    char telefone[11];
    char email[50];
    char data_nasc[10];
    char data_diag[10];
    char comorbidade[50];
} Paciente;

typedef struct profSaude {
    char senha[50];
    char login[50];
} ProfSaude;

void cadastro(Paciente *paciente) {
    printf("Nome: ");
    fflush(stdin);
    fgets(paciente->nome, 50, stdin); // fgets(nome, 50, stdin); > para ler espaços em branco usando o fgets
    printf("CPF: ");
    scanf("%s", paciente->cpf); // nao funciona com espacos em branco
    printf("Telefone: ");
    scanf("%s", paciente->telefone);
    printf("Endereco: ");
    fgets(paciente->endereco, 50, stdin); 
    printf("Data de nascimento: ");
    scanf("%s", paciente->data_nasc);
    printf("Email: ");
    scanf("%s", paciente->email);
    printf("Data do diagnostico: ");
    scanf("%s", paciente->data_diag);
    printf("Comorbidade: ");
    fgets(paciente->comorbidade, 50, stdin);
}

void login(ProfSaude *profSaude) {
    do {
        printf("Login: ");
        scanf("%s", profSaude->login);
        printf("Senha: ");
        scanf("%s", profSaude->senha);

        if (strcmp(profSaude->login, "medico") == 0 && strcmp(profSaude->senha, "123") == 0) {
            printf("Login efetuado com sucesso!\n");
        } else {
            printf("Login ou senha incorretos!\n");
        }
    } while (strcmp(profSaude->login, "medico") != 0 || strcmp(profSaude->senha, "123") != 0);
}

void salvar(Paciente *paciente) {
    FILE *Ponteiro;
    Ponteiro = fopen("cadastro.txt", "a");

    if (Ponteiro == NULL) {
        printf("Erro na abertura do arquivo!");
        exit(1);
    }

    fprintf(Ponteiro, "Nome: %s", paciente->nome);
    fprintf(Ponteiro, "CPF: %s", paciente->cpf);
    fprintf(Ponteiro, "Telefone: %s", paciente->telefone);
    fprintf(Ponteiro, "Endereco: %s", paciente->endereco);
    fprintf(Ponteiro, "Data de nascimento: %s", paciente->data_nasc);
    fprintf(Ponteiro, "Email: %s", paciente->email);
    fprintf(Ponteiro, "Data do diagnostico: %s", paciente->data_diag);
    fprintf(Ponteiro, "Comorbidade: %s", paciente->comorbidade);
}

int main() {
    Paciente paciente;
    int opcao;

    ProfSaude profSaude;
    login(&profSaude);

    do {
        printf("1 - Cadastrar paciente\n");
        printf("2 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastro(&paciente);
                salvar(&paciente);
                printf("Cadastro realizado com sucesso!\n");
                printf("Cadastrar novo paciente? (1 - Sim / 2 - Nao)\n");
                scanf("%d", &opcao);
            case 2:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 2);

    return 0;
}