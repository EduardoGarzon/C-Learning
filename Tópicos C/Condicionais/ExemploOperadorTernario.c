// Operador condicional - ?
// Operador Ternario

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2;

    printf("Informe dois numeros:  \n");
    scanf("%i %i", &num1, &num2);

    num1 > num2 ? printf("Numero %i maior que numero %i", num1, num2) : printf("Numero %i maior que numero %i", num2, num1);

    system("pause");
    return 0;
}