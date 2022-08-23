/* Passagem de parametro por referecia, utilizando ponteiros
para retornar mais de um valor dentro da mesma funcao  */

#include <stdio.h>
#include <math.h>

float potencia(float *x, float *y) // ponteiros recebem o endereco de memoria de x e y
{
    *x = pow(*x, 2);
    *y = pow(*y, 2);
    printf("\nResultados Funcao Secundaria: x = %0.2f e y = %0.2f", *x, *y);
}

int main()
{
    float x = 0, y = 0; // variaveis

    printf("Informe um valor para x e y [ex: 1 2]: ");
    scanf("%f%f", &x, &y);

    printf("\nX e Y elevados a 2:\n");
    potencia(&x, &y); // passando por parametro o endereco de memoria das variaveis
    printf("\nResultados da Principal: x = %0.2f e y= %0.2f", x, y); // valores de x e y ja alterados por conta da passagem de paramentro por referenia 

    return 0;
}