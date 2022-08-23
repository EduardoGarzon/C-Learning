/*
2. Implemente uma função recursiva que, dados dois números inteiros x e
n, calcula o valor de xn.
*/

#include <stdio.h>

int potencia(base, exp) // funcao recursiva que calcula a potencia 
{
    if (exp == 0)
    {
        return 1;
    }
    else
    {
        return (base * potencia(base, exp - 1)); 
    }
}

int main()
{
    int base = 0, exp = 0; // variaveis para base e exp

    printf("Informe o valor da base e do expoente: "); // lendo valor para base e expoente
    scanf("%d%d", &base, &exp);

    int pot = potencia(base, exp);                                // chamada da funcao que calcula a potencia
    printf("Base %d elevado ao expoente %d: %d", base, exp, pot); // imprimindo resultados

    return 0;
}