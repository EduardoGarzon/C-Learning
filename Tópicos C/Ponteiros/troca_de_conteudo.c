/*
Trocando o centeudo de duas variaveis por meio de ponteiros.
*/

#include <stdio.h>
#include <stdlib.h>

void trocaValores(float *A, float *B)
{
    float C = *A;
    *A = *B;
    *B = C;
}

int main()
{
    float A = 10, B = 20;

    printf("Valor de A: %f | Valor de B: %f\n", A, B);
    trocaValores(&A, &B);
    printf("Valor de A: %f | Valor de B: %f\n", A, B);

    system("pause");
    return 0;
}