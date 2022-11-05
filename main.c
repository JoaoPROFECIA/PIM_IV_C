/* Programa para cadastro de pacientes diagnosticados com Covid-19 */
#include <stdio.h>   /* printf, scanf, fgets */
#include <stdlib.h>  /* system */
#include <string.h>  /* para usar o fgets */
#include <locale.h>  /* para usar acentos */
#include <unistd.h>  /* para usar a funcao sleep */


/* definindo a struct Paciente e ProfSaude */
typedef struct paciente 
{
    /* constantes do paciente */
    char nome[50];
    char cpf[11];
    char cep[9];
    char rua[50];
    char numero[10];
    char bairro[50];
    char cidade[50];
    char estado[50];
    char telefone[11];
    char email[50];
    char data_nasc[10];
    char data_diag[10];
    char comorbidade[50];

} Paciente;


typedef struct profSaude 
{
    /* constantes de login do profissional */
    char senha[50];
    char login[50];

} ProfSaude;


/* funcao para cadastrar paciente */
void cadastro(Paciente *paciente) 
{

    printf("Nome: ");
    fflush(stdin);
    fgets(paciente->nome, 50, stdin);  /* fgets > para ler espaços em branco usando o fgets */
    printf("CPF: ");
    scanf("%s", paciente->cpf);        /* scanf > nao funciona com espacos em branco */
    printf("Telefone: ");
    scanf("%s", paciente->telefone);
    printf("Email: ");
    scanf("%s", paciente->email);
    printf("Endereco completo: ");
    printf("CEP: ");
    fgets(paciente->cep, 9, stdin); 
    printf("Rua: ");
    fgets(paciente->rua, 50, stdin);
    printf("Numero: ");
    fgets(paciente->numero, 10, stdin);
    printf("Bairro: ");
    fgets(paciente->bairro, 50, stdin);
    printf("Cidade: ");
    fgets(paciente->cidade, 50, stdin);
    printf("Estado: ");
    fgets(paciente->estado, 50, stdin);
    printf("Data de nascimento: ");
    scanf("%s", paciente->data_nasc);
    printf("Data do diagnostico: ");
    scanf("%s", paciente->data_diag);
    printf("Comorbidade: ");
    fgets(paciente->comorbidade, 50, stdin);

}


/* funcao para login do profissional de saude */
void login(ProfSaude *profSaude) 
{

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


/* funcao para salvar os dados do paciente em um arquivo */
void salvar(Paciente *paciente) 
{

    FILE *Ponteiro;
    Ponteiro = fopen("cadastro.txt", "a");

    if (Ponteiro == NULL) 
    {
        printf("Erro na abertura do arquivo!");
        exit(1);
    }

    fprintf(Ponteiro, "Nome: %s", paciente->nome);
    fprintf(Ponteiro, "CPF: %s", paciente->cpf);
    fprintf(Ponteiro, "Telefone: %s", paciente->telefone);
    fprintf(Ponteiro, "Email: %s", paciente->email);
    fprintf(Ponteiro, "Endereco: %s", paciente->cep);
    fprintf(Ponteiro, "Rua: %s", paciente->rua);
    fprintf(Ponteiro, "Numero: %s", paciente->numero);
    fprintf(Ponteiro, "Bairro: %s", paciente->bairro);
    fprintf(Ponteiro, "Cidade: %s", paciente->cidade);
    fprintf(Ponteiro, "Estado: %s", paciente->estado);
    fprintf(Ponteiro, "Data de nascimento: %s", paciente->data_nasc);
    fprintf(Ponteiro, "Data do diagnostico: %s", paciente->data_diag);
    fprintf(Ponteiro, "Comorbidade: %s", paciente->comorbidade);
}


/* funcao para menu */
void menu()
{

    Paciente paciente;
    int opcao;

    do 
    {
        printf("1 - Cadastrar paciente\n");
        printf("2 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastro(&paciente);
                salvar(&paciente);
                printf("Cadastro realizado com sucesso!\n");

            case 2:
                printf("Salvando e saindo");
                for (int i = 0; i < 3; i++) {
                    printf(".");
                    sleep(1);
                }
                break;

            default:                      
                printf("Opcao invalida!\n");

        }

    } while (opcao != 2);

}


/* programa principal */
int main() 
{

    ProfSaude profSaude;  /* declarando a struct ProfSaude */

    login(&profSaude);    /* chamando a funcao login */
    menu();               /* chamando a funcao menu */

    return 0;

}