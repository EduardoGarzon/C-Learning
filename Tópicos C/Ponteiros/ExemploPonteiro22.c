/*
    Implemente uma função que calcule a área da superfície e
    o volume de uma esfera de raio R.

    Essa função deve obedecer ao protótipo:
        void calc_esfera(float R, float *area, float *volume)

    A área da superfície e o volume são dados, respectivamente, por:
        A = 4 * pi * R2
        V = 4/3 * pi * R3
*/

#include <stdio.h>
#include <stdlib.h>

#define pi 3.14

void calc_esfera(float R, float *area, float *volume)
{
    *area = 4 * pi * R * R;             // calculo da area
    *volume = (4 / 3) * pi * R * R * R; // calculo do volume
}

int main()
{
    float R = 0.0;
    float area, volume;

    printf("Informe o valor de Raio: ");
    scanf("%f", &R);

    calc_esfera(R, &area, &volume); // funcao pra calcular area e volume

    printf("\n");
    printf("Area da superficie da esfera: %f\n", area);
    printf("Volume da esfera: %f\n", volume);

    system("pause");
    return 0;
}