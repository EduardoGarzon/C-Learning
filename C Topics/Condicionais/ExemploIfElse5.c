/*
    Elabore um programa que leia três valores para os lados de um triângulo,
    considerando lados como A, B e C.

    Inicialmente, verifique se os lados fornecidos formam um triângulo (A<B+C; B<A+C; C<A+B).

    Sendo um triângulo, em seguida identifique o tipo,
    se equilátero (A=B=C); isósceles (A=B ou A=C ou B=C),
    ou escaleno (A diferente de B e B diferente de C).
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ladoA, ladoB, ladoC;

    printf("Informe o lado A: ");
    scanf("%d", &ladoA);

    printf("Informe o lado B: ");
    scanf("%d", &ladoB);

    printf("Informe o lado C: ");
    scanf("%d", &ladoC);

    printf("\n");

    if ((ladoA < ladoB + ladoC) && (ladoB < ladoA + ladoC) && (ladoC < ladoA + ladoB))
    {
        printf("Os lados informados formam um triangulo.\n");
        if (ladoA == ladoB && ladoB == ladoC)
        {
            printf("Triangulo Equilatero.\n");
        }
        else if ((ladoA == ladoB) || (ladoA == ladoC) || (ladoB == ladoC))
        {
            printf("Triangulo Isosceles.\n");
        }
        else
        {
            printf("Triangulo Escaleno.\n");
        }
    }
    else
    {
        printf("Os lados informados nao formam um triangulo.\n");
    }

    system("pause");
    return 0;
}