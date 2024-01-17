/*
    Conversão de Base – B para 10 sem parte fracionaria
    - ajbj+ aj-1bj-1+ ... + a2b2+ a1b1+ a0b0
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int novo = 0;   // valor obtido da conversao
    int numero = 0; // numero a ser convertido
    int vet[7];     // vetor para armazenar os algarismos
    int base = 0;   // valor da base
    int i = 0;      // contador

    printf("Informe um numero inteiro: ");
    scanf("%d", &numero);

    printf("Informe a base do numero inteiro: ");
    scanf("%d", &base);

    while (numero > 0)
    {
        // armazena cada algarismo de acordo com a formula
        vet[i] = (numero % 10) * (pow(base, i));
        numero = numero / 10; // pega o proximo algarismo
        novo += vet[i];       // soma os algarismos calculados
        i++;
    }

    printf("================================================\n");
    printf("Valor convertido para a base 10: %d\n", novo);
    printf("================================================\n");

    system("pause");
    return 0;
}