/* 13) Faça um algoritmo que o usuário informa um número e o algoritmo verifica se ele é
um número triangular. Obs.: Um número é triangular quando é o resultado do produto de
três números consecutivos. Exemplo: 24 = 2 x 3 x 4. */

#include <stdio.h>

int main()
{
    int numero, cont;

    printf("informe um numero: ");
    scanf("%i", &numero);

    for (cont = 0; (cont * (cont + 1) * (cont + 2)) < numero; cont++)
        ;

    if ((cont * (cont + 1) * (cont + 2)) == numero)
    {
        printf("\nNumero triangular.");
    }
    else
    {
        printf("\nNumero nao triangular.");
    }
    return 0;
}
