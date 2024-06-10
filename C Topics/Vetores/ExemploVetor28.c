/*
    Considerande vetores de 10 posições do tipo real
    e armazenando no segundo vetor, o número digitado no primeiro vetor,
    menos 15%. Ao final, mostre ambos os vetores.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float vetor1[10], vetor2[10];
    float numero;

    for (int i = 0; i <= 9; i++)
    {
        printf("Informe um valor real: ");
        scanf("%f", &numero);

        vetor1[i] = numero;
        vetor2[i] = vetor1[i] * 0.15;
    }

    printf("\n\n");
    printf("Vetor 1:\n");
    for (int i = 0; i <= 9; i++)
    {
        printf("Posicao %i - Valor %0.1f\n", i, vetor1[i]);
    }

    printf("\n\n");
    printf("Vetor 1 com valores -15%%:\n");
    for (int i = 0; i <= 9; i++)
    {
        printf("Posicao %i - Valor %0.1f\n", i, vetor2[i]);
    }

    system("pause");
    return 0;
}