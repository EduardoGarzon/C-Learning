#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, columns;
    char s;

    printf("Informe o numero de linhas: ");
    scanf("%d", &rows);

    printf("Informe o numero de colunas: ");
    scanf("%d", &columns);

    scanf("%c");

    printf("Informe o simbolo: ");
    scanf("%c", &s);

    for (int i = 0; i <= rows; i++)
    {
        for (int j = 0; j <= columns; j++)
        {
            printf("%c", s);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}