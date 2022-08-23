/* Elabore um programa que leia três valores para os lados de um triângulo, considerando lados como A, B e C.
Inicialmente, verifique se os lados fornecidos formam um triângulo (A<B+C; B<A+C; C<A+B). Sendo um
triângulo, em seguida identifique o tipo, se equilátero (A=B=C); isósceles (A=B ou A=C ou B=C), ou escaleno
(A diferente de B e B diferente de C) (Adaptado de (Forbellone e Eberspacher). 11/03/2022 */

#include <stdio.h>

int main()
{
    int ladoA, ladoB, ladoC;

    printf("Informe o lado A: ");
    scanf("%i", &ladoA);

    printf("Informe o lado B: ");
    scanf("%i", &ladoB);

    printf("Informe o lado C: ");
    scanf("%i", &ladoC);

    if ((ladoA < ladoB + ladoC) && (ladoB < ladoA + ladoC) && (ladoC < ladoA + ladoB))
    {
        printf("\nOs lados informados formam um triangulo.");
        if (ladoA == ladoB && ladoB == ladoC)
        {
            printf("\nTriangulo Equilatero.");
        }
        else if ((ladoA == ladoB) || (ladoA == ladoC) || (ladoB == ladoC))
        {
            printf("\nTriangulo Isosceles.");
        }
        else
        {
            printf("\nTriangulo Escaleno.");
        }
    }
    else
    {
        printf("\nOs lados informados nao formam um triangulo.");
    }
    return 0;
}