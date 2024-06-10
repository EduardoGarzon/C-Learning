/*
    Faça um algoritmo que calcule a média aritmética de duas notas de 10 alunos.
    Após este processamento, mostre a média de cada um dos alunos.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float notas[3];
    float soma = 0;

    for (int indice = 0; indice <= 2; indice++)
    {
        printf("Informe a nota %d: ", indice);
        scanf("%f", &notas[indice]);

        soma += notas[indice];
    }

    soma /= 3;

    printf("\n");
    printf("Media das notas informadas: %0.1f\n", soma);

    for (int indice = 0; indice <= 2; indice++)
    {
        printf("Nota %d : %0.1f\n", indice, notas[indice]);
    }

    system("pause");
    return 0;
}