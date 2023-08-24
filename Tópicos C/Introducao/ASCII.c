// escrevendo os caracteres e seu codigo equivalente em ASCII

#include <stdio.h>

int main()
{
    setlocale();
    char caractere;

    printf("Informe um caractere: ");
    scanf("%c", &caractere);
    printf("Caractere: %c | ASCII: %d", caractere, caractere);

    printf("\n\nquebra de linha\n");
    printf("\ttabulacao\ttabulacao\n");
    printf("backspace\bbackspace\b\n");
    printf("\rRetorno de linha\r\n");
    printf("beep!\a\n");
    printf("contrabarra\\\n");
    
    printf("caractere especial alt+167 ou alt+0186: ");
    scanf(" %c", &caractere);
    printf("Caractere: %c", caractere);

    return 0;
}