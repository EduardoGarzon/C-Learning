#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void *pointerFunction()
{
    printf("Funcionou!\n");
}

int main()
{
    HEADER h;
    h.pointer = pointerFunction;

    h.pointer();

    system("pause");
    return 0;
}