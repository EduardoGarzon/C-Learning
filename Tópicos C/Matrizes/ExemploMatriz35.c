#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}};

    int rows = sizeof(matriz) / sizeof(matriz[0]);
    int columns = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    printf("Rows: %d\n", rows);
    printf("Columns: %d\n\n", columns);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}