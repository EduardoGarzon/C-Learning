/*    Faça um algoritmo que calcule a média aritmética de duas notas de 10 alunos. Após este
processamento, mostre a média de cada um dos alunos. 18/03/2022 */

#include <stdio.h>

int main()
{
    float notas[3];
    float soma = 0;

    for (int indice = 0; indice < 3; indice++)
    {
        printf("Informe a nota %i: ", indice);
        scanf("%f", &notas[indice]);

        soma += notas[indice];
    }

    soma /= 3;
    printf("\nMedia das notas informadas: %0.1f", soma);

    for (int indice = 0; indice < 3; indice++)
    {
        printf("\nNota %i : %0.1f", indice, notas[indice]);
    }
    return 0;
}