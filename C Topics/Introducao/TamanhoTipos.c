#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Tamanhos de Bytes de cada tipo primitivo

    int valor1;
    float valor2;
    char valor3;

    long int valor4;
    long long int valor5;

    short int valor6;

    double valor7;
    long double valor8;

    unsigned int valor9;
    unsigned short int valor10;
    unsigned long int valor11;
    unsigned long long int valor12;
    unsigned char valor13;

    int a = sizeof valor1;
    int b = sizeof valor2;
    int c = sizeof valor3;
    int d = sizeof valor4;
    int e = sizeof valor5;
    int f = sizeof valor6;
    int g = sizeof valor7;
    int h = sizeof valor8;
    int i = sizeof valor9;
    int j = sizeof valor10;
    int k = sizeof valor11;
    int l = sizeof valor12;
    int m = sizeof valor13;

    printf("int: %d Bytes\n", a);
    printf("float: %d Bytes\n", b);
    printf("char: %d Bytes\n", c);

    printf("\n");

    printf("long int: %d Bytes\n", d);
    printf("long long int: %d Bytes\n", e);

    printf("\n");

    printf("short int: %d Bytes\n", f);

    printf("\n");

    printf("double: %d Bytes\n", g);
    printf("long double: %d Bytes\n", h);

    printf("\n");

    printf("unsigned int: %d Bytes\n", i);
    printf("unsigned short int: %d Bytes\n", j);
    printf("unsigned long int: %d Bytes\n", k);
    printf("unsigned long long int: %d Bytes\n", l);
    printf("unsigned char: %d Bytes\n", m);

    system("pause");
    return 0;
}