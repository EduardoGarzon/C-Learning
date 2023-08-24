/* Desenvolver um algoritmo que leia 5 nomes de usuarios contendo apenas caracteres e sem espacos. 
Caso o nome ja exista, informar o usuario e pedir que digite outro nome. 
No final, mostrar a lista de todos os nomes informados. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char nome[5][10]; // Vetor de 5 espacos para strings de 10 caracteres cada;
    char usuario[10]; // String de 10 caracteres;
    int flag = 0;
    
    printf("Cadastre 5 usuarios\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nInforme o nome de usuario: ");
        scanf("%s", usuario); // leitura do nome do usuario;

        for (int x = 0; x < i; x++) // compara o nome informado com o conteudo do vetor string nome;
        {
            if (strcmp(&usuario, &nome[x]) == 0) // funcao de comparacao de strings da biblioteca <stdlib.h>;
            {
                flag = 1; // strcmp = 0 e flag = 1, entao o conteudo de usuario ja existem em nome. 
            }
        }

        if (flag == 0)
        {
            strcpy(nome[i], usuario); // funcao da biblioteca <string.h> para atribuicao de strings;
        }
        else
        {
            printf("\nNome de usuario ja cadastrado, informe outro.\n");
            flag = 0;
            i--;
        }
    }
    
    printf("\nUsuarios cadastrados: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("\n%i - %s\n", i, nome[i]);
    }

    return 0;
}