/*
    Utilizando strncmp.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[100] = {"xxxxxx"};

    // Compara apenas os n primeiros caracteres de ambas strings.
    int resultado = strncmp(string, "aaaaaa", 5);
    
    printf("strncmp(nome, teste, 5) == %d\n", resultado);

    system("pause");
    return 0;
}
