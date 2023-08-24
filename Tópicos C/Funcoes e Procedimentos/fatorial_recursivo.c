/*
Calculando o fatorial por funcao recursiva

empilhar: ocorre ate o criterio de parada
    2 * 1
    3 * fatorial(2)
    4 * fatorial(3)

desempilhar: realiza a multiplicacao agora que sabe por quais valores multiplicar n
    2 * 1
    3 * fatorial(2)
    4 * fatorial(6)
    24
*/

#include <stdio.h>
#include <stdlib.h>

int fatorial_recursivo(int numero)
{
    if (numero == 0 || numero == 1)
    {
        return 1;
    }
    else
    {
        return numero * fatorial_recursivo(numero - 1);
    }
}

int main()
{
    int numero = 0;
    printf("Informe um valor inteiro: ");
    scanf("%d", &numero);

    printf("FATORIAL RECURSIVO DE %d: %d\n", numero, fatorial_recursivo(numero));

    system("pause");
    return 0;
}