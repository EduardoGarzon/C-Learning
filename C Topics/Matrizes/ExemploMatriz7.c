/* Procurar um número numa matriz 3x3 */

#include <stdio.h>
#include <stdlib.h>

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
    printf("Qual valor deseja procurar na matriz?: ");
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

    flag == 1 ? printf("Valor encontrado.\n") : printf("Valor nao encontrado.\n");

    system("pause");
    return 0;
}