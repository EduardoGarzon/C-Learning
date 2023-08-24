// funcao iscntrl() ctype.h

#include <stdio.h>
#include <ctype.h>

int main()
{
    /*
    int isctrnl()
    Recebe: um único argumento (caractere) que será convertido para inteiro. Mesmo que iscntrl() receba um inteiro como argumento, o caractere é passado para a função. Internamente, o caractere é convertido em seu valor ASCII para a verificação.

    Retorna: um valor diferente de zero caso seja um caractere de controle (códigos de 0 a 31 na tabela ASCII) ou 0 caso contrário.
    */

    int num, resultado;
    char c;

    c = 'a';
    resultado = iscntrl(c);
    printf("Letra minuscula: %d\n", resultado);

    c = 'B';
    printf("Letra maiuscula: %d\n", iscntrl(c));

    c = '1';
    printf("numero em char: %d\n", iscntrl(c));

    num = 1;
    printf("numero em int: %d\n", iscntrl(num));

    c = '\n';
    printf("caracter de controle: %d\n", iscntrl(c));

    return 0;
}