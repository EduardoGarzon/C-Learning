#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cars[][10] = {"Onix", "HB20", "Fusca", "Camaro"};

    strcpy(cars[0], "Corvette");

    for (int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++)
    {
        printf("%s\n", cars[i]);
    }

    system("pause");
    return 0;
}