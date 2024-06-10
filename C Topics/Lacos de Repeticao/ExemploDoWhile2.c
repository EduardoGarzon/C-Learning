#include <stdio.h>
#include <stdlib.h>

int main()
{
    int value;
    int maior = 0;

    do
    {
        printf("Informe um valor: ");
        scanf("%d", &value);

        if (value > maior)
        {
            printf("Novo maior valor informado: %d\n", value);
        }

        printf("\n");

    } while (value != 0);

    system("pause");
    return 0;
}