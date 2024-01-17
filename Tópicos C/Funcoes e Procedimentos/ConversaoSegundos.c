/*
    Faça uma função que receba 3 números inteiros como parâmetro,
    representando horas, minutos e segundos, e os converta em segundos,
    retornando a informação.
*/

#include <stdio.h>
#include <stdlib.h>

void segundos(int horas, int min, int seg)
{
    // funcao sem retorno que escreve na tela os segundos e o total da soma deles
    printf("Horas em segundos: %d segundos\n", horas *= 3600);
    printf("Minutos em segundos: %d\n", min *= 60);
    printf("Segundos: %d\n", seg);
    printf("Total de segundos: %d\n", (horas + min + seg));
}

int main()
{
    int horas = 0, min = 0, seg = 0; // variaveis para horas, minutos e segundos

    printf("Informe as horas, minutos e segundos: ");
    scanf("%d%d%d", &horas, &min, &seg);
    printf("\n");

    // chamada para a funcao que converte tudo para segundos e soma todos os segundos
    segundos(horas, min, seg);

    system("pause");
    return 0;
}