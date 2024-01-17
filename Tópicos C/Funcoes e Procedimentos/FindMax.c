#include <stdio.h>
#include <stdlib.h>

int findMax(int x, int y)
{
    return (x > y) ? x : y;
}

int main()
{
    int x, y;

    printf("Informe um valor inteiro para x e y: ");
    scanf("%d%d", &x, &y);

    printf("O maior valor é: %d\n", findMax(x, y));

    system("pause");
    return 0;
}