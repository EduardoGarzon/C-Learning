#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i = 1, j, M[2][6];
    for (j = 0; j < 3; j++)
    {
        M[i][j] = 95;
        M[i][j + 1] = 89;
        M[i][j + 2] = 83;
        M[i][j + 3] = 77;
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%i  ", M[i][j]);
        }
        printf("\n");
    }

    system("pause");
}