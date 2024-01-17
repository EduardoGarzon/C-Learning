/* Obter o maior e o menor dos elementos de uma matriz 3x3 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[3][3];
    int i, j, numero;
    int maior = 0;
    int menor = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Informe um valor para %dx%d: ", i, j);
            scanf("%d", &numero);

            matriz[i][j] = numero;

            if (numero >= maior)
            {
                maior = numero;

                if (menor == 0)
                {
                    menor = numero;
                }
            }
            if (numero <= menor)
            {
                menor = numero;
            }
        }
    }

    printf("\n");
    printf("Matriz 3x3: ");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }

    printf("\n");
    printf("Menor valor da matriz: %d\n", menor);
    printf("Maior valor da matriz: %d\n", maior);

    system("pause");
    return 0;
}