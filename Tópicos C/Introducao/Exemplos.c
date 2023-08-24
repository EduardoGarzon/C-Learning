/* Testes em C */

#include <stdio.h>
#include <conio.h>

int main()
{
    printf("\a");             // executa um sinal sonoro
    printf("abc\b\b\bABC\n"); // Imprime abc, apaga e depois imprime ABC e quebra a linha
    printf("xyz\tXYZ\n");       // Imprime xyz, a tabulação e XYZ
    printf("\\\n");             // Imprime uma barra
    printf("\"\n");             // Imprime aspas

    float numero;
    printf("Informe um numero float: ");
    scanf("%f", &numero);
    printf("Numero formatado: %8.2f\n", numero); // O código de formatação %8.2f indica que o formato de impressão do número do tipo float será de tamanho total 8, sendo 2 o tamanho da parte fracionária.

    // funções getch e getche, que capturam e retornam o caractere digitado no teclado
    // Ambos são definidos na biblioteca de funções conio.
    printf("Informe um caractere: ");
    char c = getch(); // getch não exibe o caractere digitado na tela.
    fflush(stdin);
    printf("\nCaractere informado: %c", c);

    printf("\nInforme outro caractere: ");
    char c2 = getche();
    fflush(stdin);
    printf("\nCaractere informado: %c", c);
    return 0;
}