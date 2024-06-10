/*
    Crie uma função chamada “delta” que receba três valores a, b e c, que são
    os coeficientes de uma equação do segundo grau e retorne ao programa
    principal o valor calculado, que é dado por: delta = b² - 4ac.

    Δ < 0, então a equação não possui resultados reais;

    Δ = 0, então a equação possui apenas um resultado real ou possui dois resultados iguais (essas duas afirmações são equivalentes);

    Δ > 0, então a equação possui dois resultados distintos reais."
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int delta(int a, int b, int c, int det)
{
    det = (pow(b, 2) - (4 * a * c));
    return det;
}

int main()
{
    int a = 0, b = 0, c = 0, det = 0; // coeficientes

    printf("Informe um valor para a: ");
    scanf("%d", &a);
    printf("Informe um valor para b: ");
    scanf("%d", &b);
    printf("Informe um valor para c: ");
    scanf("%d", &c);
    printf("\n");

    det = delta(a, b, c, det);

    printf("Valor do Delta: %d\n", det);

    if (det < 0)
    {
        printf("A equacao nao possui resultados reais.\n");
    }
    else if (det == 0)
    {
        printf("A equacao possui apenas um resultado real ou os dois sao iguais.\n");
    }
    else
    {
        printf("A equacao possui resultados distintos.\n");
    }

    system("pause");
    return 0;
}