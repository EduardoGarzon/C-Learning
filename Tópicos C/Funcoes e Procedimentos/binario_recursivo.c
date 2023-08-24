/*
Funcao recursiva pra decimal em binario

exemplo:
        Resultado Resto
    4/2 - 2        0
    2/2 - 1        0
    numero binario: 100b ou 4d
    Divisoes sucessivas do numero por 2 ate que o resultado seja 0 e/ou o resto seja 1
*/

#include <stdio.h>
#include <stdlib.h>

void binario_Recursivo(int decimal)
{
    if (decimal == 0) // SE RESULTADO == 0
    {
        printf("%d", decimal);
    }
    else
    {
        binario_Recursivo(decimal / 2); // RESULTADO
        printf("%d", decimal % 2);      // RESTO
    }
}

int main()
{
    int decimal = 0;
    printf("Informe um numero decimal inteiro positivo: ");
    scanf("%d", &decimal);
    printf("%d decimal em binario recursivo:\n", decimal);
    binario_Recursivo(decimal);
    printf("\n");
    system("pause");
    return 0;
}