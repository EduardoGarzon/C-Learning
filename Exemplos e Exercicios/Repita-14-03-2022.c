/* Utilizando a estrutura “repita”, implemente em linguagem de programação C um algoritmo que leia
um conjunto de 20 números inteiros compreendidos entre 150 e 550, e determine e imprima o maior e
o menor número fornecido. */

#include <stdio.h>

int main()
{
    int numero, cont, maior, menor;

    printf("Informe um numero entre 150 e 550: ");
    scanf("%i", &numero);

    if ((numero >= 150) && (numero <= 500))
    {
        maior = numero;
        menor = numero;
        cont = 1;

        do
        {
            printf("Informe um numero entre 150 e 550: ");
            scanf("%i", &numero);

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
                printf("\nInforme um valor valido.\n");
            }

        } while (cont < 3);

        printf("\nMenor numero: %i", menor);
        printf("\nMaior numero: %i", maior);
    }
    else
    {
        printf("Erro! informe um valor valido. ");
    }
    return 0;
}