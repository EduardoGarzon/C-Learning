/* 
    Chico tem 1,50m e cresce 2 centímetros por ano, 
    enquanto Juca tem 1,10m e cresce 3 centímetros por ano. 
    Construir um algoritmo que calcule e imprima quantos anos 
    serão necessários para que Juca seja maior que Chico. 
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float chico = 150, juca = 110, tempo = 0;

    while (juca <= chico)
    {
        juca += 3;
        chico += 2;
        tempo++;
    }

    printf("Juca sera maior que Chico em %i, anos\n", tempo);
    
    system("pause");
    return 0;
}