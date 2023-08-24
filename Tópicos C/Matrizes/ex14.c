/* 14. Desenvolva um algoritmo que leia uma matriz M(3x3)
com valores necessariamente entre 0 e 5 e gere uma nova matriz FAT(3x3)
com os fatoriais dos respectivos valores da matriz M. Imprima ambas as matrizes. */

#include <stdio.h>

int main()
{
    int M[3][3], FAT[3][3];
    int i, j, numero;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Infome um valor de 0 ate 5 para %dx%d: ", i, j); // lendo o numero
            scanf("%d", &numero);
            if (numero > 5 || numero < 0) // testando se o numero informa esta de 0 ate 5
            {
                printf("\nNumero invalido, insira outro valor.\n\n");
                i = i;
                j--;
            }
            else
            {
                M[i][j] = numero; // matriz M recebe o numero se ele estiver no intervalo 0 ate 5
                if (numero == 0)  // fatorial de 0 == 1
                {
                    numero = 1;
                    FAT[i][j] = numero;
                }
                else
                {
                    for (int x = numero - 1; x > 0; x--) // calculando o fatorial do numero
                    {
                        numero *= x;
                    }
                    FAT[i][j] = numero; // matriz FAT recebe o novo numero
                }
            }
        }
    }

    printf("\nMatriz M: \n"); // escrevendo a matriz M
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%2d ", M[i][j]);
        }
    }

    printf("\n\nMatriz Fatorial de M: \n"); // escrevendo a matriz fatorial
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%2d ", FAT[i][j]);
        }
    }

    return 0;
}