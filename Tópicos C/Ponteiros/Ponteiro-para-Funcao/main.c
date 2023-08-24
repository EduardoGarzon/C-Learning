#include <stdio.h>
#include "header.h"

void *sexo()
{
    printf("nao\n");
    return NULL;
}

int main()
{
    HEADER h;
    h.pointer = sexo;

    h.pointer();

    return 0;
}