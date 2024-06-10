/*
    Faça um algoritmo que o usuário informe um número
    e o algoritmo verifica se ele é um número triangular.

    Obs.: Um número é triangular quando é o resultado do produto de
    três números consecutivos. Exemplo: 24 = 2 x 3 x 4.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, cont;

    printf("Informe um numero: ");
    scanf("%d", &numero);

    for (cont = 0; (cont * (cont + 1) * (cont + 2)) < numero; cont++);

    if ((cont * (cont + 1) * (cont + 2)) == numero)
    {
        printf("Numero triangular.\n");
    }
    else
    {
        printf("Numero nao triangular.\n");
    }

    system("pause");
    return 0;
}
