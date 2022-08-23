/* 6. Escreva uma função que dado um número real passado como parâmetro, retorne a
parte inteira e a parte fracionária deste número. Escreva um programa que chama esta
função.
Protótipo:
void frac(float num, int* inteiro, float* frac);
*/

#include <stdio.h>

void frac(float numero, int *inteiro, float *fracao)
{
    *inteiro = numero;           // separa parte inteira
    *fracao = numero - *inteiro; // separa parte fracionada
}
int main()
{
    float numero = 0.0;
    int inteiro;
    float fracao;

    printf("Informe um numero real: ");
    scanf("%f", &numero);
    frac(numero, &inteiro, &fracao); // chamada da funcao com passagem de parametro por referencia

    printf("Parte inteira: %d\n", inteiro);
    printf("Parte fracionaria: %g\n", fracao);
    return 0;
}