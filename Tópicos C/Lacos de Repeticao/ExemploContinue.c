/*
    Break termina o laco de repeticao atual, saindo dele.
    Continue forca a proxima interacao, pula.
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{

    for (int i = 0; i <= 10; i++)
    {
        if (i == 13)
        {
            continue;
        }

        if (i == 50)
        {
            break;
        }

        printf("%d ", i);
    }

    system("pause");
    return 0;
}