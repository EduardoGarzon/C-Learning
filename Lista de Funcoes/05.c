/* 5. Faça uma função que receba 3 números inteiros como parâmetro,
representando horas, minutos e segundos, e os converta em segundos,
retornando a informação. */

#include <stdio.h>

void segundos(int horas, int min, int seg)
{
    // funcao sem retorno que escreve na tela os segundos e o total da soma deles
    printf("\nHoras em segundos: %d segundos", horas *= 3600);
    printf("\nMinutos em segundos: %d", min *= 60);
    printf("\nSegundos: %d", seg);
    printf("\nTotal de segundos: %d", (horas + min + seg));
}

int main()
{
    int horas = 0, min = 0, seg = 0; // variaveis para horas, minutos e segundos

    printf("Informe as horas, minutos e segundos: ");
    scanf("%d%d%d", &horas, &min, &seg);

    segundos(horas, min, seg); // chamada para a funcao que converte tudo para segundos e soma todos os segundos

    return 0;
}