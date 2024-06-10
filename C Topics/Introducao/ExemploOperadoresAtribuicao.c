// Exemplos utilizando operadores de atribuicao em C.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5, c = 0;

    printf("Testando operadores de atribuição sendo a=%d e c=%d \n", a, c);
    c = a; // c é 5
    printf("Quando c = a,  c = %d\n", c);
    c += a; // c é 10
    printf("Quando c += a,  c = %d\n", c);
    c -= a; // c é 5
    printf("Quando c -= a, c = %d\n", c);
    c *= a; // c é 25
    printf("Quando c *= a, c = %d\n", c);
    c /= a; // c é 5
    printf("Quando c /= a, c = %d\n", c);
    c %= a; // c = 0
    printf("Quando c %%= a, c = %d\n", c);

    system("pause");
    return 0;
}
