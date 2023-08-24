/* 12. Armazenar 20 números inteiros em um vetor NUM.
Imprima a posição do vetor, o número armazenado e uma das mensagens “par” ou “ímpar”,
de acordo com o número constante em NUM. */

#include <stdio.h>

int main()
{
    int num[20];

    for (int i = 0; i < 20; i++)
    {
        printf("Informe o valor: ");
        scanf("%i", &num[i]);
    }

    for (int i = 0; i < 20; i++)
    {
        printf("Posicao: %i | Valor: %i | %s\n", i, num[i], num[i] % 2 == 0 ? "Par" : "Impar");
    }
    return 0;
}