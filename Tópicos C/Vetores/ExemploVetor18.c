/*
    Faça um algoritmo para ler dois vetores V1 e V2 de 15 números cada.

    Informar a quantidade de vezes que V1 e V2
    possuem os mesmos números nas mesmas posições.

    Caso não existam mesmos números nas mesmas posições, informar.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v1[15], v2[15];
    int flag = 0;

    for (int i = 0; i < 15; i++)
    {
        printf("Informe um valor para o Vetor 1: ");
        scanf("%d", &v1[i]);
    }
    
    printf("\n");

    for (int i = 0; i < 15; i++)
    {
        printf("Informe um valor para o Vetor 2: ");
        scanf("%d", &v2[i]);

        if (v2[i] == v1[i])
        {
            flag++;
        }
    }

    printf("\n");
    printf("Numeros iguais nas mesmas posicoes de V1 e V2: %d\n", flag);

    system("pause");
    return 0;
}