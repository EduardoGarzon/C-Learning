/*
    Faça um programa que tenha uma função double potencia(double x, int n)
    e a utilize para calcular o valor de um número real elevado a um número
    inteiro.

    O double é para números grande e com uma precisão de 15 casas decimais,
    para pegar um número double coloque lf de long float : scanf("%lf",&num);
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double potencia(double x, int n, double resultado)
{
    resultado = pow(x, n); // funcao que calcula a potencia
    return resultado;      // retorna o resultado para main
}

double main()
{
    double x = 0;         // base da potencia
    int n = 0;            // expoente da potencia
    double resultado = 0; // variavel para resultado

    printf("Informe um valor real para a base: ");
    scanf("%lf", &x);
    printf("Informe um valor inteiro para ao expoente: ");
    scanf("%d", &n);

    resultado = potencia(x, n, resultado); // chamada da funcao que retorna a potencia

    printf("Resultado da potencia: %.2f\n", resultado);

    system("pause");
    return 0;
}