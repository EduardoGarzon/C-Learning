/*
    & = AND

        x ->  6 -> 00000110;
        y -> 12 -> 00001100;
        z -> 4  -> 00000100;

    | = OR

        x ->  6 -> 00000110;
        y -> 12 -> 00001100;
        z -> 14  -> 00001110;

    ^ = XOR

        x ->  6 -> 00000110;
        y -> 12 -> 00001100;
        z -> 10 -> 00001010;

    << = left shift

        x ->  6 -> 00000110;
        y -> 12 -> 00001100;

        z ->  6  -> 00000110;
        z ->  6  -> 0000110;
        z ->  12 -> 00001100;

    >> = right shift

        x ->  6  -> 00000110;

        z ->  6  -> 00000110;
        z ->  6  -> 0000000110;
        z ->  1 -> 00000001;

*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int x = 6;
    int y = 12;
    int z = 0;

    // AND
    z = x & y;
    printf("AND: %d\n", z);

    // OR
    z = x | y;
    printf("OR: %d\n", z);

    // XOR
    z = x ^ y;
    printf("XOR: %d\n", z);

    // Left Shift
    z = x << 1;
    printf("Left Shift: %d\n", z);

    // Right Shift
    z = x >> 2;
    printf("Right Shift: %d\n", z);

    system("pause");
    return 0;
}