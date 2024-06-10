/*
    Desenvolva um programa que leia a quantidade total de segundos e
    converta para Horas, Minutos e Segundos.

    Imprima o resultado da conversão no formato HH:MM:SS.

    Para isso, utilize a função com protótipo:
        void converteHora(int total segundos, int *hora, int *min, int *seg)
*/

#include <stdio.h>
#include <stdlib.h>

void converteHora(int total_segundos, int *hora, int *min, int *seg)
{
    *hora = total_segundos / 3600;
    total_segundos = total_segundos % 3600;
    *min = total_segundos / 60;
    *seg = total_segundos % 60;
}

int main()
{
    int total_segundos, hora, min, seg;

    printf("Informe o total de segundos: ");
    scanf("%d", &total_segundos);

    converteHora(total_segundos, &hora, &min, &seg);

    printf("\n");
    printf("[HH:MM:SS] - [%2d:%2d:%2d]\n", hora, min, seg);

    system("pause");
    return 0;
}
