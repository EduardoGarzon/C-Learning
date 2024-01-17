// leia um número e imprima se: 'é múltiplo de 3' ou 'não é múltiplo de 3'.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;

    printf("Informe um numero inteiro positivo: ");
    scanf("%d", &numero);

    if ((numero %= 3) == 0)
    {
        printf("\n");
        printf("Numero Multiplo de 3.\n");
    }
    else
    {
        printf("\n");
        printf("Numero nao multiplo de 3.\n");
    }

    system("pause");
    return 0;
}