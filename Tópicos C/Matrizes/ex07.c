/* 7. Desenvolva um algoritmo que leia uma matriz 4x4 e então gire seus elementos no sentido horário,
ou seja, a primeira linha passa a ser a última coluna e assim sucessivamente. */

#include <stdio.h>

int main()
{
    int matriz[4][4]; // Matriz
    int i, j, aux;    // indices e variavel auxiliar

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Informe um valor para %dx%d: ", i, j); // Lendo os valores da matriz
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz Normal: ");
    for (i = 0; i < 4; i++)
    {
        printf("\n");
        for (j = 0; j < 4; j++)
        {
            printf("%2d ", matriz[i][j]); // Escrevendo a matriz normal
        }
    }

    printf("\nMatriz Transposta: ");
    for (i = 0; i < 4; i++) // Transpondo a matriz utilizando apenas uma variavel auxiliar
    {
        for (j = i + 1; j < 4; j++) // j = i+1 para nunca i==j e assim nao alterar a DP
        {
            if (j != i) // Teste para transpor os valores que nao sao da DP
            {
                aux = matriz[i][j];          // a variavel aux recebe o elemento A da posicao A
                matriz[i][j] = matriz[j][i]; // a posicao A recebe o elemento B da posicao B
                matriz[j][i] = aux;          // a posicao B recebe a variavel aux contendo o elemento A
            }
        }
    }

    for (i = 0; i < 4; i++) // Transcrevendo coluna 3 com coluna 0
    {
        aux = matriz[i][0];
        matriz[i][0] = matriz[i][3];
        matriz[i][3] = aux;
    }
    for (i = 0; i < 4; i++) // Transcrevendo coluna 2 com coluna 1
    {
        aux = matriz[i][1];
        matriz[i][2] = matriz[i][1];
        matriz[i][2] = aux;
    }

    for (i = 0; i < 4; i++) // escrendo a matriz com os elementos girados em 90 graus
    {
        printf("\n");
        for (j = 0; j < 4; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }

    return 0;
}