#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Imprime a parte final do triângulo, à direita

    char vet[] = {"fulano"};
    int tamanho = strlen(vet) - 1;

    for (int i = tamanho; i >= 0; i--)
    {
        // imprime espaços à esquerda
        for (int j = 0; j < i; j++)
            printf(" ");
        // imprime a parte esquerda do triângulo
        for (int k = i; k <= tamanho; k++)
            printf("%c", vet[k]);
        // imprime a parte direita do triângulo
        for (int m = tamanho - 1; m >= i; m--)
            printf("%c", vet[m]);
        printf("\n");
    }

    system("pause");
    return 0;
}