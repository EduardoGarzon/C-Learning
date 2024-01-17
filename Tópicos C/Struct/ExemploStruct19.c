/*
    Faça um programa que leia um vetor com dados de 5 livros:
    título (máximo 30 letras), autor (máximo 15 letras) e ano.
    Procure um livro por título, perguntando ao usuário qual título deseja buscar.
    Mostre os dados de todos os livros encontrados.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    struct livros // estrutura que armazena os dados dos livros
    {
        char titulo[30];
        char autor[15];
        int ano;
    } livro[5];

    int i = 0; // indice dos for

    printf("Cadastre os livros:\n");

    for (i = 0; i < 5; i++) // leitura dos dados para os livros
    {
        printf("Informe o titulo do livro: ");
        fgets(livro[i].titulo, 30, stdin);
        fflush(stdin);

        printf("Informe o autor do livro: ");
        fgets(livro[i].autor, 15, stdin);
        fflush(stdin);

        printf("Informe o ano do livro: ");
        scanf("%d", &livro[i].ano);
        fflush(stdin);

        printf("\n");
    }

    char procurado[30]; // string que armazena o titulo procurado informado pelo usuario
    int flag = 0;       // flag que indica se o titulo foi encotrado
    int resposta = 1;   // variavel de resposta para ver se o usuario quer continuar procurando

    while (resposta == 1) // enquanto a resposta for 1 ele continua procurando o livro
    {
        flag = 0;

        printf("Procure o livro pelo titulo: "); // leitura do titulo
        fgets(procurado, 30, stdin);
        fflush(stdin);

        for (i = 0; i < 5; i++) // comparado o titulo informado com os titulos da estrutura
        {
            if (strcmp(procurado, livro[i].titulo) == 0)
            {
                printf("Titulo: %s", livro[i].titulo);
                printf("Autor: %s", livro[i].autor);
                printf("Ano: %d", livro[i].ano);

                flag = 1; // titulo achado a flag recebe 1
            }
        }

        if (flag == 0) // flag em 0 == livro nao encontrado
        {
            printf("Livro nao encontrado.\n");
        }

        printf("Continuar? [0 - nao / 1 - sim]: "); // opcao de continuar
        scanf("%d", &resposta);
        fflush(stdin);
    }

    system("pause");
    return 0;
}