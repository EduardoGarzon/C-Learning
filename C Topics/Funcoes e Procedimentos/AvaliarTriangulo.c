/*
    Crie um programa que receba três valores (obrigatoriamente maiores que
    zero), representando as medidas dos três lados de um triângulo.

    Elabore funções para:
        a. Determinar se os lados formam um triângulo, sabendo que:
            - O comprimento de cada lado de um triângulo é menor do que a
            soma dos outros dois lados.
        b. Determinar e mostrar o tipo de triângulo, caso as medidas formem
        um triângulo. Sendo que:
            - Chama-se equilátero o triângulo que tem três lados iguais.
            - Denominam-se isósceles o triângulo que tem o comprimento de
            dois lados iguais.
            - Recebe o nome de escaleno o triângulo que tem os três lados
            diferentes.
*/

#include <stdio.h>
#include <stdlib.h>

void triangulo(int ladoA, int ladoB, int ladoC)
{
    // teste para verificar se os valores informados sao maiores que zero
    if (ladoA > 0 && ladoB > 0 && ladoC > 0)
    {
        // teste para verificar se os valores informados formam um triangulo
        if (ladoA < (ladoB + ladoC) && ladoB < (ladoA + ladoC) && ladoC < (ladoA + ladoB))
        {
            printf("Os valores formam um triangulo.\n");
            if (ladoA == ladoB && ladoB == ladoC) // testes para verificar o tipo do triangulo.
            {
                printf("Triangulo Equilatero.\n");
            }
            else if (ladoA != ladoB && ladoB != ladoC && ladoC != ladoA)
            {
                printf("Triangulo Escaleno.\n");
            }
            else if (ladoA == ladoB || ladoB == ladoC || ladoC == ladoA)
            {
                printf("Triangulo Isosceles.\n");
            }
        }
        else
        {
            printf("Os valores nao formam um triangulo.\n");
        }
    }
    else
    {
        printf("Valores menores ou iguais a zero nao sao aceitos!\n");
    }
}

int main()
{
    int ladoA = 0, ladoB = 0, ladoC = 0; // variaveis para os lados do triangulo

    printf("Informe os lados A, B, C: ");
    scanf("%d%d%d", &ladoA, &ladoB, &ladoC);
    printf("\n");

    // funcao sem retorno que verifica a possibilidade de ser um triangulo e ainda o seu tipo
    triangulo(ladoA, ladoB, ladoC);

    system("pause");
    return 0;
}