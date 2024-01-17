#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a = 'A';
    char b = 'B';
    char c = 'C';

    printf("%d bytes\n", sizeof(a));
    printf("%d bytes\n", sizeof(b));
    printf("%d bytes\n", sizeof(c));

    printf("\n");

    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &c);

    system("pause");
    return 0;
}