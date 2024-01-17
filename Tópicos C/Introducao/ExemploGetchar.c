#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;

    printf("Informe uma letra: ");
    letra = getchar();

    printf("Caractere informado %c\n", letra);

    /*
        Diferente do scanf() o getchar() tambem serve para ler 
        carateres do teclado e nao precisa de parametros, 
        é uma funcao de atribuicao sobre uma variavel que recebe o dado lido.
    */

    system("pause");
    return 0;
}