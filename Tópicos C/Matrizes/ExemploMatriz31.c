/*
    Proponha o enunciado de um algoritmo que utiliza duas matrizes,
    que não tenha sido ainda resolvido pela nossa turma e o resolva.

    Gere duas matrizes 3x3 com valores aleatorios
    e permita que o usuario troque seus valores, um por vez,
    entre ambas as matrizes, mostre na tela a cada atribuicao as duas matrizes.

    Repita o processo enquanto o usuario desejar.
    Ainda, em um vetor armazene os valores escolhidos de cada matriz pelo usuario.

    Repita todo o processo quantas vezes o usuario desejar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int A[3][3], B[3][3], vetor[18];                // matrizes e vetor
    int i, j, x, y, w = 0;                          // indices das matriezes e do vetor
    int aux;                                        // auxiliar para troca entre matrizes
    int resposta = 0, resposta2 = 0, resposta3 = 0; // opcoes de resposta

    // total de segundos passados desde 1 de janeiro de 1970 até a data atual.
    srand(time(NULL));

    printf("Matriz A :\n"); // Matriz A
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            A[i][j] = rand() % 20; // atribuindo valores aleatorios em A

            printf("%2d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Matriz B:\n"); // Matriz B
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            B[i][j] = rand() % 20; // atribuindo valores aleatorios em B

            printf("%2d ", B[i][j]);
        }
        printf("\n");
    }

    while (resposta2 == 0) // repete o menu enquanto resposta for 0
    {
        printf("\n\n");
        printf("|--------------------------------------|\n"); // menu de opcoes
        printf("| 1 - Adicionar valores no vetor       |\n");
        printf("| 0 - Trocas valores entre as matrizes |\n");
        printf("|--------------------------------------|\n");
        printf("Opcao: ");
        scanf("%d", &resposta); // lendo a opcao desejada

        if (resposta == 0)
        {
            // trocando valores entre as matrizes enquanto resposta == 0
            while (resposta == 0)
            {
                printf("\n");
                printf("Informe a posicao de A: "); // lendo posicao de A
                scanf("%d%d", &x, &y);

                aux = A[x][y];

                printf("Informe a posicao de B: "); // lendo posicao de B
                scanf("%d%d", &i, &j);

                A[x][y] = B[i][j];
                B[i][j] = aux;

                printf("\n");
                printf("Matriz A:\n"); // escrevendo A
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 3; j++)
                    {
                        printf("%2d ", A[i][j]);
                    }
                    printf("\n");
                }

                printf("\n");
                printf("Matriz B:\n"); // escrevendo B
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 3; j++)
                    {
                        printf("%2d ", B[i][j]);
                    }
                    printf("\n");
                }

                printf("\n");
                // opcao de repeticao da operacao
                printf("\nContinuar? [sim - 0 | nao - 1]: ");
                scanf("%d", &resposta);
            }

            printf("\n");
            // opcao de finalizar o programa ou voltar ao menu
            printf("| 0 - Voltar ao menu      |\n");
            printf("| 1 - Finalizar progarama |\n");
            printf("Opcao: ");
            scanf("%d", &resposta2);
        }
        else if (resposta == 1) // adiciona valores das matrizes no vetor
        {
            while (resposta == 1) // adicionar enquanto resposta == 1
            {
                printf("\n");
                printf("Informe a Matriz: [0 - A | 1 - B]: "); // lendo a matriz desejada
                scanf("%d", &resposta3);

                if (resposta3 == 0) // lendo a posicao da matriz A
                {
                    printf("\n");
                    printf("Informe a posicao de A: ");
                    scanf("%d%d", &x, &y);

                    if (w < 18) // verifica se o vetor ja nao esta cheio
                    {
                        vetor[w] = A[x][y];
                        w++;
                    }
                    else
                    {
                        printf("\n");
                        printf("Vetor full\n");
                    }

                    printf("\n");
                    printf("Continuar? [sim - 1 | nao - 0]: "); // opcao de repeticao
                    scanf("%d", &resposta);
                }
                else if (resposta3 == 1) // lendo a posicao da matriz B
                {
                    printf("\n");
                    printf("Informe a posicao de B: ");
                    scanf("%d%d", &x, &y);

                    if (w < 18)
                    {
                        vetor[w] = B[x][y];
                        w++;
                    }
                    else
                    {
                        printf("\n");
                        printf("Vetor full\n");
                    }

                    printf("\n");
                    printf("Continuar? [sim - 1 | nao - 0]: "); // opcao de repeticao
                    scanf("%d", &resposta);
                }
            }

            printf("\n");
            printf("Vetor: "); // escreve o vetor ate onde foi atribuido
            for (i = 0; i < w; i++)
            {
                printf("%d ", vetor[i]);
            }

            printf("\n");
            printf("| 0 - Voltar ao menu      |\n");
            printf("| 1 - Finalizar progarama |\n");
            printf("Opcao: ");
            scanf("%d", &resposta2);
        }
    }

    system("pause");
    return 0;
}