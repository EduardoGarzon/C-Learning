/* 
    Fazer um algoritmo que simule a operação
    de um relógio (horas, minutos e segundos). 
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int seg, min, horas;

    min = 0;
    horas = 0;

    for (seg = 0; seg <= 60; seg++)
    {
        if (seg == 60)
        {
            seg = 0;
            min++;
        }
        if (min == 60)
        {
            min = 0;
            horas++;
        }
        if (horas == 24)
        {
            break;
        }

        printf("%i | %i | %i\n", horas, min, seg);
    }

    system("pause");
    return 0;
}