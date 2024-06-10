#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5, b = 5, c = 10;

    printf("Testando operadores relacinoais sendo a=%d, b=%d e c=%d\n", a, b, c);
    printf("Retorna 1 quando verdadeiro e 0 quando falso\n");
    printf("%d == %d é %d\n", a, b, a == b);
    printf("%d == %d é %d\n", a, c, a == c);
    printf("%d > %d é %d\n", a, b, a > b);
    printf("%d > %d é %d\n", a, c, a > c);
    printf("%d < %d é %d\n", a, b, a < b);
    printf("%d < %d é %d\n", a, c, a < c);
    printf("%d != %d é %d\n", a, b, a != b);
    printf("%d != %d é %d\n", a, c, a != c);
    printf("%d >= %d é %d\n", a, b, a >= b);
    printf("%d >= %d é %d\n", a, c, a >= c);
    printf("%d <= %d é %d\n", a, b, a <= b);
    printf("%d <= %d é %d\n", a, c, a <= c);

    system("pause");
    return 0;
}
