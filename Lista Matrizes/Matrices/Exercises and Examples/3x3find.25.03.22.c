/* Procurar um número numa matriz 3x3 */

#include <stdio.h>

int main()
{
    int matriz[3][3];
    int i, j, x;
    int flag = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Informe um valor para %dx%d: ", i, j);
            scanf("%d", &x);
            matriz[i][j] = x;
        }
    }

    printf("\nMatriz 3x3: ");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }

    printf("\n\nQual valor deseja procurar na matriz?: ");
    scanf("%d", &x);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (x == matriz[i][j])
            {
                flag = 1;
            }
        }
    }

    flag == 1 ? printf("\nValor encontrado.") : printf("\nValor nao encontrado.");

    return 0;
}