/* 18. Ler um vetor B de 10 elementos e considere que podem existir elementos repetidos.
A seguir copie para um vetor C apenas os elementos de B que não se repetem.
Por fim, escreva o vetor C ou informe a respeito do caso extremo.
Exemplo: B= 7 4 4 5 7 2 1 3 4 6;  C= 5 2 1 3 6 */

#include <stdio.h>

int main()
{

    int vetorB[10], vetorC[10];
    int numero = 0;
    int flag = 0;
    int y = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Informe um numero: ");
        scanf("%i", &vetorB[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        numero = vetorB[i];
        for (int x = 0; x < 10; x++)
        {
            if (numero == vetorB[x])
            {
                flag++;
            }
        }

        if (flag == 1)
        {
            vetorC[y] = vetorB[i];
            y++;
        }
        flag = 0;
    }

    printf("\nVetor sem elementos repetido: \n");
    for (int i = 0; i < y; i++)
    {
        printf("%i\n", vetorC[i]);
    }

    return 0;
}