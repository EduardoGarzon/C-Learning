// 10. Utilizando o Visualg, leia um número e imprima se: 'é múltiplo de 3' ou 'não é múltiplo de 3'.

#include <stdio.h>

int main()
{
    int numero;

    printf("Informe um numero inteiro positivo: ");
    scanf("%i", &numero);

    if ((numero %= 3) == 0)
    {
        printf("\nNumero Multiplo de 3.");
    }
    else
    {
        printf("Numero nao multiplo de 3.");
    }
    return 0;
}