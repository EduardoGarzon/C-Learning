/*
    A multiplicação de dois números inteiros
    pode ser feita através de somas sucessivas.

    Proponha um algoritmo recursivo Multip_Rec(n1,n2)
    que calcule a multiplicação de dois inteiros.
*/

#include <stdio.h>
#include <stdlib.h>

int multi(int n1, int n2, int result)
{
    if (n1 == 0 || n2 == 0) // soma consecutivamente o primeiro valor ate o segundo se igual 0
    {
        return result;
    }
    else
    {
        result += n1;

        return (multi(n1, n2 - 1, result));
    }
}

int main()
{
    int n1 = 0, n2 = 0, result = 0;

    printf("Informe o valor de n1 e n2: "); // lendo os valores
    scanf("%d%d", &n1, &n2);

    printf("%d\n", multi(n1, n2, result)); // chamada da fucao que multiplica os valores

    system("pause");
    return 0;
}