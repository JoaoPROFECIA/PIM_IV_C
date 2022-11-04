/* Programa para cadastro de pacientes diagnosticados com Covid-19 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* login e cadastro do paciente */

int main(void){
    /* definicao de ponteiro para o arquivo */
    FILE *Ponteiro;
    /* definicao de variaveis */
    char nome[50], cpf[11], endereco[50], telefone[11], email[50], senha[50], login[50], data_nasc[10], data_diag[10], comorbidade[50];

    /* abertura do arquivo */
    Ponteiro = fopen("cadastro.txt", "a");

    /* verificacao de erro na abertura do arquivo */
    if(Ponteiro == NULL){
        printf("Erro na abertura do arquivo!");
        exit(1);
    }
    
    /* login do medico */

    // COMFLITO COM A FUNCAO DE CADASTRO DO PACIENTE "NOME"

    /*do {
        printf("Login: ");
        scanf("%s", login);
        printf("Senha: ");
        scanf("%s", senha);

        if(strcmp(login, "medico") == 0 && strcmp(senha, "123") == 0){
            printf("Login efetuado com sucesso!\n");
        } else {
            printf("Login ou senha incorretos!\n");
        }
    }while (strcmp(login, "medico") != 0 || strcmp(senha, "123") != 0);

    */

    /* cadastro do paciente */
    printf("Nome: ");
    // scanf("%s", nome); // nao funciona com espacos em branco 
    // scanf("%50[^\n]", nome); // >>> para ler espaços em branco usando o scanf
    fgets(nome,50, stdin); // fgets(nome, 50, stdin); > para ler espaços em branco usando o fgets
    printf("O nome digitado foi: %s", nome);
    printf("CPF: ");
    scanf("%s", cpf);
    printf("Telefone: ");
    scanf("%s", telefone);
    printf("Endereco: ");
    fgets(endereco, 50, stdin);
    printf("Data de nascimento: ");
    scanf("%s", data_nasc);
    printf("Email: ");
    scanf("%s", email);
    printf("Data do diagnostico: ");
    scanf("%s", data_diag);
    printf("Comorbidade: ");
    fgets(comorbidade, 50, stdin);

    /* escrita no arquivo */
    fprintf(Ponteiro, "\n\nNome: %s \nCPF: %s \nTelefone: %s \nEndereco: %s \nData de nascimento: %s \nEmail: %s \nData do diagnóstico: %s \nComorbidade: %s \n\n", nome, cpf, telefone, endereco, data_nasc, email, data_diag, comorbidade);

    /* fechamento do arquivo */
    fclose(Ponteiro);
    printf("Cadastro finalizado");

    return 0;
}