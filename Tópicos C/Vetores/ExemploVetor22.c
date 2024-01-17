/*
    Ler um vetor B de 10 elementos e considere que podem existir elementos repetidos.
    A seguir copie para um vetor C apenas os elementos de B que não se repetem.
    Por fim, escreva o vetor C ou informe a respeito do caso extremo.

    Exemplo: B= 7 4 4 5 7 2 1 3 4 6;  C= 5 2 1 3 6
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetorB[10], vetorC[10];
    int numero = 0;
    int flag = 0;
    int y = 0;

    for (int i = 0; i <= 9; i++)
    {
        printf("Informe um numero: ");
        scanf("%d", &vetorB[i]);
    }

    for (int i = 0; i <= 9; i++)
    {
        numero = vetorB[i];

        for (int x = 0; x <= 9; x++)
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

    printf("\n");
    printf("Vetor sem elementos repetido:\n");
    for (int i = 0; i < y; i++)
    {
        printf("%d ", vetorC[i]);
    }

    system("pause");
    return 0;
}