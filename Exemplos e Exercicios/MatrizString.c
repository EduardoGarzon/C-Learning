// Fazendo uma matriz de Strings

#include <stdio.h>

int main()
{
    char string[5][30]; // char vet[numero_de_strings][tamanho_dos_strings];

    for (int i = 0; i < 5; i++)
    {
        printf("Informe sua string: "); // escrita feita na string da vez
        gets(string[i]);
        fflush(stdin);
    }

    for (int i = 0; i < 5; i++) // escrevendo as strings
    {
        printf("\n%s", string[i]);
    }

    return 0;
}