/* Exemplo de Struct */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct exemplo // nome da struct
    {
        int idade;
        char nome[50];
    } dados[2]; // variavel da struct

    for (int i = 0; i < 2; i++) // informando dados da struct
    {
        printf("Informe o nome: ");
        fgets(dados[i].nome, 50, stdin);
        fflush(stdin);

        printf("Informe a idade: ");
        scanf("%d", &dados[i].idade);
        fflush(stdin);

        printf("\n");
    }

    printf("Imprimindo Struct de dados:\n");
    for (int i = 0; i < 2; i++) // imprimindo dados da struct
    {
        printf("\n");
        printf("Nome: %s", dados[i].nome);
        printf("Idade: %d\n", dados[i].idade);
    }

    system("pause");
    return 0;
}