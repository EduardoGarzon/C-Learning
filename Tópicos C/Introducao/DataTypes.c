#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Biblioteca para utiliar o tipo bool.

int main()
{
    char a = 'C';         // single character    -> %c
    char b[] = "Eduardo"; // array of characters -> %s

    float c = 3.141592;           // 4 bytes (32 bits of precision: 6 - 7 digits) -> %f
    double d = 3.141592653589793; // 8 bytes (64 bits of precision: 6 - 7 digits) -> %lf

    bool e = true; // 1 byte (true 1 or false 0) -> %d

    char f = 120;          // 1 byte (-128 to +127) -> %d (int) or %c (ASCII value);
    unsigned char g = 255; // 1 byte (0 to +255)    -> %d (int) or %c (ASCII value);

    short h = 32767;          // 2 bytes (-32,768 to +32,767) -> %d
    unsigned short i = 65535; // 2 butes (0 to +65,535)       -> %d

    int j = 2147483647;          // 4 bytes (-2,147,483,648 to +2,147,483,647) -> %d
    unsigned int k = 4294967295; // 4 bytes (0 to +4,294,967,295)              -> %u

    // 8 bytes (-9 quintillion to +9 quintillion) -> %lld
    long long int l = 9223372036854775807;
    // 8 bytes (0 to +18 quintillion)             -> %llu
    unsigned long long int m = 18446744073709551615U;

    printf("Single Character: %c\n", a);
    printf("Array of Characters: %s\n", b);

    printf("\n");

    printf("Float: %f\n", c);
    printf("Double: %lf\n", d);

    printf("\n");

    printf("Bool: %d\n", e);

    printf("\n");

    printf("Char as int value: %d\n", f);
    printf("Char as ASCII value: %c\n", f);

    printf("Unsigned Char as int value: %d\n", g);
    printf("Unsigned Char as ASCII value: %c\n", g);

    printf("\n");

    printf("Short: %d\n", h);
    printf("Unsigned Short: %d\n", i);

    printf("\n");

    printf("Int: %d\n", j);
    printf("Unsigned Int: %u\n", k);

    printf("\n");

    printf("Long Long Int: %lld\n", l);
    printf("Unsigned Long Long Int: %llu\n", m);

    printf("\n");

    system("pause");
    return 0;
}