/* Teste em C com getch e getche*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    // funções getch e getche, que capturam e retornam o caractere digitado no teclado
    // Ambos são definidos na biblioteca de funções conio.

    printf("Informe um caractere: ");
    char c = getch(); // getch não exibe o caractere digitado na tela.
    getchar();

    printf("\n");
    printf("Caractere informado: %c\n", c);

    printf("\n");

    printf("Informe outro caractere: ");
    c = getche();
    getchar();

    printf("\n");
    printf("Caractere informado: %c\n", c);

    system("pause");
    return 0;
}