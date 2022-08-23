/*
8. Faça um programa que leia uma quantidade qualquer de números armazenando-os na
memória e pare a leitura quando o usuário entrar um número negativo. Em seguida,
imprima o vetor lido. Use a função REALLOC. Obs. Os números deverão ser armazenados no
vetor enquanto forem positivos.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 1;
    int *vetor = malloc(i * sizeof(int));
    int *vetor2;
    int numero = 0;

    printf("Informe um valor [Negativo para encerrar]: ");
    scanf("%d", &numero);
    vetor[i] = numero;

    while (numero > 0)
    {
        printf("Informe um valor [Negativo para encerrar]: ");
        scanf("%d", &numero);
        vetor2 = realloc(vetor, i++ * sizeof(int));
        vetor2[i] = numero;
         vetor = vetor2;
    }

    for (int j = 1; j < i; j++)
    {
        printf("[%d] ", vetor[j]);
    }
    free(vetor);
    free(vetor2);

    return 0;
}