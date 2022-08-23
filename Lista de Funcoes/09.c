/*
9. Faça uma função que receba por parâmetro dois valores x e z. Calcule e
retorne o resultado de xZ para o programa principal. Atenção não utilize
nenhuma função pronta de exponenciação.
*/

#include <stdio.h>

int potencia(int x, int z, int y)
{
    if (z == 0)
    {
        x = 1;
    }
    else
    {
        y = x;
        for (int i = 1; i < z; i++)
        {
            x *= y;
        }
    }

    return x;
}

int main()
{
    int x = 0, z = 0, y = 0;

    printf("Informe a base: ");
    scanf("%d", &x);
    printf("Informe o expoente: ");
    scanf("%d", &z);

    x = potencia(x, z, y);

    printf("Resultado da potencia: %d", x);
    return 0;
}