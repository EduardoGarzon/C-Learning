#include <stdio.h>

int main()
{
    printf("Digite um caractere: ");
    char letra = getc(stdin);
    printf("Caractere informado: %c\n", letra);

    /*
        Assim como scanf e getchar, a funcao getc tambem le caracteres informados 
        alem de arquivos de texto porem, recebe como parametro de onde o dado é lido, 
        no caso do teclado utilizamos a palavra reservada stdin.
    */

    return 0;
}