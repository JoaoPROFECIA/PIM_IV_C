/* Programa para cadastro de pacientes diagnosticados com Covid-19 */
#include <stdio.h> /* printf, scanf, fgets */
#include <stdlib.h> /* malloc */
#include <string.h> /* para usar o fgets */
#include <locale.h> /* para usar acentos */
#include <unistd.h> /* para usar a funcao sleep */

/* Definindo a struct Paciente e ProfSaude */
typedef struct paciente {
    char nome[50];
    char cpf[11];
    char telefone[20];
    char email[50];
    char cep[12];
    char rua[50];
    char numero[10];
    char bairro[50];
    char cidade[50];
    char estado[50];
    char data_nasc[10];
    char data_diag[10];
    char comorbidade[50];
} Paciente;

typedef struct profSaude {
    char senha[50];
    char login[50];
} ProfSaude;


/* funcao para cadastrar paciente */
void cadastro(Paciente *paciente) {
    printf("\nPreencha os dados abaixo\n\n");
    printf("Nome: ");
    fflush(stdin); /* stdin > limpa o buffer do teclado */
    fgets(paciente->nome, 50, stdin); /* fgets > para ler espaços em branco usando o fgets ||| scanf > nao funciona com espacos em branco */
    printf("CPF (somente numeros): ");
    fflush(stdin);
    fgets(paciente->cpf, 11, stdin); 
    printf("Telefone com DDD (somente numeros): ");
    fflush(stdin);
    fgets(paciente->telefone, 20, stdin);
    printf("Email: ");
    fflush(stdin);
    fgets(paciente->email, 50, stdin);
    printf("ENDERECO COMPLETO: \n");
    printf("CEP: ");
    fflush(stdin);
    fgets(paciente->cep, 12, stdin); 
    printf("Rua: ");
    fflush(stdin);
    fgets(paciente->rua, 50, stdin);
    printf("Numero: ");
    fflush(stdin);
    fgets(paciente->numero, 10, stdin);
    printf("Bairro: ");
    fflush(stdin);
    fgets(paciente->bairro, 50, stdin);
    printf("Cidade: ");
    fflush(stdin);
    fgets(paciente->cidade, 50, stdin);
    printf("Estado: ");
    fflush(stdin);
    fgets(paciente->estado, 50, stdin);
    printf("Data de nascimento: ");
    fflush(stdin);
    scanf("%s", paciente->data_nasc);
    printf("Data do diagnostico: ");
    fflush(stdin);
    scanf("%s", paciente->data_diag);
    printf("Comorbidade: ");
    fflush(stdin);
    fgets(paciente->comorbidade, 50, stdin);
}


/* funcao para login do profissional de saude */
void login(ProfSaude *profSaude) {
    do {
        printf("Realize o login para continuar\n");
        printf("Login: ");
        scanf("%s", profSaude->login);
        printf("Senha: ");
        scanf("%s", profSaude->senha);

        if (strcmp(profSaude->login, "medico") == 0 && strcmp(profSaude->senha, "123") == 0) {
            printf("\nLogin efetuado com sucesso!\n\n");
        } else {
            printf("\nLogin ou senha incorretos!\n\n");
        }
    } while (strcmp(profSaude->login, "medico") != 0 || strcmp(profSaude->senha, "123") != 0);
}


/* funcao para salvar os dados do paciente em um arquivo */
void salvar(Paciente *paciente) {
    FILE *Ponteiro;
    Ponteiro = fopen("cadastro.txt", "a"); /* a > para adicionar no final do arquivo ||| w > para sobrescrever o arquivo */

    if (Ponteiro == NULL) {
        printf("Erro na abertura do arquivo!");
        exit(1);
    }

    fprintf(Ponteiro, "\nNome: %s, \nCPF: %s, \nTelefone: %s, \nEmail: %s, \nENDERECO COMPLETO\nCEP: %s, RUA: %s, NUMERO: %s, BAIRRO: %s, CIDADE: %s, ESTADO: %s, \nData de nascimento: %s, \nData do diagnostico: %s, \nComorbidade: %s", paciente->nome, paciente->cpf, paciente->telefone, paciente->email, paciente->cep, paciente->rua, paciente->numero, paciente->bairro, paciente->cidade, paciente->estado, paciente->data_nasc, paciente->data_diag,paciente->comorbidade); /* fprintf > escreve no arquivo ||| printf > escreve na tela */

    fclose(Ponteiro);
}


/* Programa principal */
int main() {
    Paciente paciente;
    int opcao;

    ProfSaude profSaude;
    login(&profSaude);

    do {
        printf("Bem vindo ao sistema de cadastro de pacientes com Covid-19!\n\n");
        printf("Escolha uma opcao:\n");
        printf("1 - Cadastrar paciente\n");
        printf("2 - Sair\n\n");
        printf("Opcao: ");
        scanf("\n%d", &opcao);

        switch (opcao) {
            case 1:
                cadastro(&paciente);
                salvar(&paciente);
                printf("Cadastro realizado com sucesso!\n\n");
                printf("1 - Retornar ao menu\n2 - Sair\n");
                printf("Opcao: ");
                scanf("\n%d", &opcao);
                if (opcao == 1) {
                    return (main());
                }
                else if (opcao == 2) {  /* para encerrar o programa apos o cadastro */
                    printf("Salvando dados e saindo");
                    for (int i = 0; i < 3; i++) {
                    printf(".");
                    sleep(1);
                    }
                    break;
                }
            case 2:  /* para encerrar o programa sem realizar o cadastro */
                printf("Saindo");               
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 2);

    return 0;
}