// Exemplos de formatacao de saída com printf.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // -------------------------------------------------------- EXEMPLO 1

    /*
        \n para saltar linha, ENTER
        \t para tabulacao, TAB
        \" para caractere de aspa duplas
        \' para caracrere de aspa simples
        \\ para caractere de barra invertida ou contra barra
    */

    printf("\n\nquebra de linha\n");
    printf("\ttabulacao\ttabulacao\n");
    printf("backspace\bbackspace\b\n");
    printf("\rRetorno de linha\r\n");
    printf("beep!\a\n"); // executa um sinal sonoro
    printf("contrabarra\\\n");
    printf("abc\b\b\bABC\n"); // Imprime abc, apaga e depois imprime ABC e quebra a linha
    printf("xyz\tXYZ\n");     // Imprime xyz, a tabulação e XYZ
    printf("\\\n");           // Imprime uma barra
    printf("\"\n");           // Imprime aspas

    // -------------------------------------------------------- EXEMPLO 2

    char caractere;

    printf("\n");
    printf("Caractere especial alt+167 ou alt+0186: ");
    scanf(" %c", &caractere);

    printf("\n");
    printf("Caractere: %c", caractere);

    system("pause");
    return 0;
}