/*
    Escreva um programa que leia um vetor de inteiros positivos
    e imprima na tela quantas vezes os números 3 e 5 apareceram no vetor, nesta ordem.
    Se não aparecerem, informe.
    O vetor terá no máximo 20 posições.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[10];
    int flag3 = 0;
    int flag5 = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Informe um valor: ");
        scanf("%d", &vetor[i]);

        if (vetor[i] == 3)
        {
            flag3++;
        }
        else if (vetor[i] == 5)
        {
            flag5++;
        }
    }

    printf("\n");
    printf("Quantidade de vezes que o numeros 3 aparece no vetor: %d\n", flag3);
    printf("Quantidade de vezes que o numeros 5 aparece no vetor: %d\n", flag5);

    system("pause");
    return 0;
}