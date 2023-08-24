// funcao isanum() ctype.h

#include <stdio.h>
#include <ctype.h>

int main()
{
    /*
    int isalnum()
    Recebe: um argumento inteiro, cujo valor seja um caractere (ou seja, possa ser representado como um unsigned char) ou o valor EOF.
    Retorna: um valor diferente de zero caso o caractere seja alfanumérico ou 0 caso contrário.
    */

    int num, resultado;
    char teste;

    teste = 'a';
    printf("resultado: %d\n", isalnum(teste));

    teste = 'a';
    resultado = isalnum(teste);
    printf("resultado: %d\n", resultado);

    teste = '+';
    resultado = isalnum(teste);
    printf("resultado: %d\n", resultado);

    num = 1;
    resultado = isalnum(num);
    printf("resultado: %d\n", resultado);

    return 0;
}