/*
2. Faça um programa que armazene em um registro de dados (estrutura composta) os
dados de um funcionário de uma empresa, compostos de: Nome, Idade, Sexo (M/F),
CPF, Data de Nascimento, Código do Setor onde trabalha (0-99), Cargo que ocupa
(string de até 30 caracteres) e Salário. Os dados devem ser digitados pelo usuário,
armazenados na estrutura e exibidos na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int flag = 0; // flag para o tratamento de erros

    struct cadastro // estrutura com os dados a serem cadastrados
    {
        char nome[50];
        char cpf[20];
        char nascimento[20];
        char cargo[30];
        char sexo;
        int idade;
        int codigo;
        float salario;

    } funcionario[3];

    for (int i = 0; i < 3; i++) // leitura dos dados para as variaveis da estrutura
    {
        printf("\n");
        printf("Informe o nome do funcionario: ");
        gets(funcionario[i].nome);
        fflush(stdin);

        printf("Informe a idade do funcionario: ");
        scanf("%d", &funcionario[i].idade);
        fflush(stdin);

        while (flag == 0) // verificacao da informacao digitada
        {
            printf("Informe o sexo do funcionario [M/F]: ");
            scanf(" %c", &funcionario[i].sexo);
            fflush(stdin);
            if (funcionario[i].sexo == 'M' || funcionario[i].sexo == 'F')
            {
                flag = 1;
            }
        }

        printf("Informe o cpf do funcionario: ");
        gets(funcionario[i].cpf);
        fflush(stdin);

        printf("Informe a data de nascimento do funcionario (ex: 31/05/2002): ");
        gets(funcionario[i].nascimento);
        fflush(stdin);

        while (flag == 1) // verificacao da informacao digitada
        {
            printf("Informe o codigo do setor do funcionario (0-99): ");
            scanf("%d", &funcionario[i].codigo);
            fflush(stdin);
            if (funcionario[i].codigo > 0 && funcionario[i].codigo < 100)
            {
                flag = 0;
            }
        }

        while (flag == 0) // verificacao da quantiadade de caracteres informados
        {
            printf("Informe o cargo do funcionario: ");
            gets(funcionario[i].cargo);
            fflush(stdin);
            if (strlen(funcionario[i].cargo) <= 30)
            {
                flag = 1;
            }
        }

        printf("Informe o salario do funcionario: R$");
        scanf("%f", &funcionario[i].salario);
        fflush(stdin);
    }

    printf("\nFuncionarios cadastrados\n"); // escrevendo os valores armazenados na estrutura
    for (int i = 0; i < 3; i++)
    {
        printf("\nNome: %s | idade: %d | sexo: %c\n", funcionario[i].nome, funcionario[i].idade, funcionario[i].sexo);
        printf("CPF: %s | Data de Nascimento: %s\n", funcionario[i].cpf, funcionario[i].nascimento);
        printf("Codigo do setor: %d | Cargo: %s | Salario: %.2f\n", funcionario[i].codigo, funcionario[i].cargo, funcionario[i].salario);
    }

    return 0;
}