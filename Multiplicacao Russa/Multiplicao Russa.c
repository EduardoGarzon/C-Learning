/* Criar um programa que realize a Multiplicação à Russa usando obrigatoriamente funções
secundárias.

A multiplicação à Russa consiste em:
a) Escrever os números A e B, que se deseja multiplicar na parte superior das colunas.
b) Dividir A por 2, sucessivamente, ignorando o resto até chegar à unidade, escrever os
resultados da coluna A.
c) Multiplicar B por 2 tantas vezes quantas se haja dividido A por 2, escrever os resultados
sucessivos na coluna B.
d) Somar todos os números da coluna B que estejam ao lado de um número ímpar da
coluna A.

Exemplo: 27 × 82
A B Parcelas
27 82 82
13 164 164
6 328 -
3 656 656
1 1312 1312
Soma: 2214
*/

#include <stdio.h>
#include <string.h>
#define size 100

void divisao(int A[]) // funcao para dividir consecutivamente os valores de A ate 1
{
    int x = 1;
    while (A[x - 1] / 2 >= 1)
    {
        A[x] = A[x - 1] / 2;
        A[x + 1] = 0;
        x++;
    }
    return A;
}

void multiplicar(int B[], int A[]) // funcao que multiplicar por 2 os valores de 2 n vezes a quantidade de vezes que A foi dividido
{
    for (int y = 1; A[y] > 0; y++)
    {
        B[y] = B[y - 1] * 2;
    }
    return B;
}

void soma(int A[], int B[], int parcelas[]) // funcao que coloca os valores de B que estao ao lado de um valor impar de A no vetor parcela para soma-los posteriormente.
{
    for (int i = 0; A[i] > 0; i++)
    {
        if (A[i] % 2 != 0)
        {
            parcelas[i] = B[i];
        }
        else
        {
            parcelas[i] = 0;
        }
    }
    return parcelas;
}

int main()
{
    int A[size], B[size], parcelas[size]; // vetores que receberao os valores
    int total = 0;                        // variavel que contem o resultado final

    printf("Informe o valor de A: ");
    scanf("%d", &A[0]);

    printf("Informe o valor de B: ");
    scanf("%d", &B[0]);

    divisao(A);           // chamada para a funcao de divisao
    multiplicar(B, A);    // chamada para a funcao de multiplicacao
    soma(A, B, parcelas); // chamada para colocar nos vetor parcela os valores de B correspondetes aos impares do vetor A

    for (int i = 0; A[i] > 0; i++)
    {
        total += parcelas[i]; // somando todos os valores do vetor parcela
    }

    for (int i = 0; A[i] > 0; i++)
    {
        printf("%d - %d - %d\n", A[i], B[i], parcelas[i]); // escrevendo os vetores
    }
    printf("SOMA TOTAL: %d", total); // escrevendo o total da soma

    return 0;
}