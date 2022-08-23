/* 11. Escrever um algoritmo que leia um vetor K[1..15].
A seguir, crie um vetor P, que contenha todos os números primos existentes em K.
Escreva o vetor P. Caso não existam números primos em K, informe. */

#include <stdio.h>

int main()
{
    int vetorK[15], vetorP[15];
    int flag = 0;
    int y = 0;
    int num;

    for (int i = 0; i < 15; i++)
    {
        printf("Informe o valor: ");
        scanf("%d", &vetorK[i]);

        for (int x = 1; x <= vetorK[i]; x++)
        {
            if (vetorK[i] % x == 0)
            {
                flag++;
            }
        }
        if (flag == 2)
        {
            vetorP[y] = vetorK[i];
            y++;
        }
        flag = 0;
    }

    printf("\nVetor Primo: \n");

    for (int i = 0; i < y; i++)
    {
        printf("%d\n", vetorP[i]);
    }
    return 0;
}