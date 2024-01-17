/*
    Desenvolver um algoritmo que leia 5 nomes de usuarios
    contendo apenas caracteres e sem espacos.

    Caso o nome ja exista, informar o usuario e pedir que digite outro nome.

    No final, mostrar a lista de todos os nomes informados.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char nome[5][10]; // Vetor de 5 espacos para strings de 10 caracteres cada;
    char usuario[10]; // String de 10 caracteres;
    int flag = 0;

    printf("Cadastre 5 usuarios\n");

    for (int i = 0; i <= 4; i++)
    {
        printf("Informe o nome de usuario: ");
        scanf("%s", usuario); // leitura do nome do usuario;

        // compara o nome informado com o conteudo do vetor string nome;
        for (int x = 0; x < i; x++)
        {
            // funcao de comparacao de strings da biblioteca <stdlib.h>;
            if (strcmp(&usuario, &nome[x]) == 0)
            {
                // strcmp = 0 e flag = 1, entao o conteudo de usuario ja existem em nome.
                flag = 1;
            }
        }

        if (flag == 0)
        {
            // funcao da biblioteca <string.h> para atribuicao de strings;
            strcpy(nome[i], usuario);
        }
        else
        {
            printf("\n");
            printf("Nome de usuario ja cadastrado, informe outro.\n");

            flag = 0;
            i--;
        }
    }

    printf("\n");
    printf("Usuarios cadastrados:\n");
    for (int i = 0; i <= 4; i++)
    {
        printf("%d - %s\n", i, nome[i]);
    }

    system("pause");
    return 0;
}