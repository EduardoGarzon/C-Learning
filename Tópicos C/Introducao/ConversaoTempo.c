/*
    Converter segundos em horas e minutos.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int horas, minutos, segundos, resto;

    printf("Informe o total de segundos: ");
    scanf("%d", &segundos);
    printf("\n");

    horas = segundos / 3600; // 1 hora == 3600 segundos
    resto = segundos % 3600; // o resto indica os minutos
    minutos = resto / 60;    // 1 minuto == 60 segundos (resto)
    segundos = resto % 60;   // o resto indica os segundos

    printf("%d : %d : %d - (hh:mm:ss)\n", horas, minutos, segundos);

    system("pause");
    return 0;
}