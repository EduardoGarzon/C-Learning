/*
    Implemente em linguagem de programação C um algoritmo que leia
    um conjunto de 20 números inteiros compreendidos entre 150 e 550,
    e determine e imprima o maior e o menor número fornecido.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, cont, maior, menor;

    printf("Informe um numero entre 150 e 550: ");
    scanf("%d", &numero);

    if ((numero >= 150) && (numero <= 500))
    {
        maior = numero;
        menor = numero;
        cont = 1;

        do
        {
            printf("Informe um numero entre 150 e 550: ");
            scanf("%d", &numero);

            if ((numero >= 150) && (numero <= 500))
            {
                if (numero > maior)
                {
                    maior = numero;
                }
                else if ((numero < maior) && (numero < menor))
                {
                    menor = numero;
                }
                cont = cont + 1;
            }
            else
            {
                printf("Informe um valor valido.\n");
            }

        } while (cont < 3);

        printf("\n");
        printf("Menor numero: %d\n", menor);
        printf("Maior numero: %d\n", maior);
    }
    else
    {
        printf("Erro! informe um valor valido.\n");
    }

    system("pause");
    return 0;
}