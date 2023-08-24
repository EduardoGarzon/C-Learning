/*
Calculando o valor de x elevado a n com potencia em funcao recursiva

2 elevado a 3:
2 * (2, 0) = 1
2 * (2, 1) = 2
2 * (4, 2) = 4
2 * (4, 3) = 8  
*/

#include <stdio.h>
#include <stdlib.h>

int potencia_Recursiva(int base, int expoente){
    if(expoente == 0)
    {
        printf("base [%d] expoente [%d]\n", base, expoente);
        return 1;
    }
    else {
        printf("base [%d] expoente [%d]\n", base, expoente);
        return base * potencia_Recursiva(base, expoente - 1);
    }   

}

int main()
{
    int base = 0;
    int expoente = 0;

    printf("Informe valores inteiros da base e do expoente: ");
    scanf("%d %d", &base, &expoente);

    printf("Potencia recursiva: %d\n", potencia_Recursiva(base, expoente));

    system("pause");
    return 0;
}