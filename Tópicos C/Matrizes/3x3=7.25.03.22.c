/* Com o programa exemplo da MatA (matriz 3 x 3) faça um programa que insira o valor 7 a
todos os seus elementos. */
#include <stdio.h>

int main()
{
    int matriz[3][3];
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            matriz[i][j] = 7;
        }
    }
    printf("Matriz 3x3 atruibuida em 7");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }

    return 0;
}