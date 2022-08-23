// funcao isalpha() ctype.h

#include <stdio.h>
#include <ctype.h>

int main()
{
    /*
    int isalpha()
    Recebe: um único argumento (caractere) que será convertido para inteiro. Mesmo que isalpha() receba um inteiro como argumento, o caractere é passado para a função. Internamente, o caractere é convertido em seu valor ASCII para a verificação.

    Retorna: 1 caso seja uma letra do alfabeto maiúscula, 2 caso seja minúscula, 0 caso não esteja no alfabeto.

    OBSERVAÇÃO: dependendo da IDE que você está usando, o valor de retorno para o caractere alfanumérico, tanto maiúsculo quanto minúsculo, pode ser diferente de 1, entretanto, sempre será zero caso não seja alfanumérico.
    */

    int num, resultado;
    char c;

    c = 'a';
    resultado = isalpha(c);
    printf("Letra minuscula: %d\n", resultado);

    c = 'B';
    printf("Letra maiuscula: %d\n", isalpha(c));

    c = '1';
    printf("numero em char: %d\n", isalpha(c));

    num = 1;
    printf("numero em int: %d\n", isalpha(num));

    return 0;
}