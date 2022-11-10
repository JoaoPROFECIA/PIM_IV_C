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
    char data_nasc[11];
    char data_diag[11];
    char comorbidade[50];
} Paciente;

typedef struct profSaude {
    char senha[50];
    char login[50];
} ProfSaude;

void calculaIdade(Paciente *paciente) {
    int dia, mes, ano, diaAtual, mesAtual, anoAtual, idade;
    printf("Digite a data de nascimento do paciente: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);
    printf("Digite a data atual: ");
    scanf("%d/%d/%d", &diaAtual, &mesAtual, &anoAtual);
    idade = anoAtual - ano;
    if (mesAtual < mes) {
        idade--;
    } else if (mesAtual == mes) {
        if (diaAtual < dia) {
            idade--;
        }
    }
    printf("Idade: %d anos\n", idade);
}

int main() {
    Paciente paciente;
    ProfSaude profSaude;
    int opcao;
    do {
        printf("1 - Cadastrar paciente\n");
        printf("2 - Login\n");
        printf("3 - Calcular idade\n");
        printf("4 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        switch (opcao) {
            /*case 1:
                cadastraPaciente(&paciente);
                break;
            case 2:
                login(&profSaude);
                break;*/
            case 3:
                calculaIdade(&paciente);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 4);
    return 0;
}
