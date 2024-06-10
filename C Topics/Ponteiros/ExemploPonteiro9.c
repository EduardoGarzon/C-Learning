/*
    Exemplo de passagem de ponteiro como parametro para funcao ou procedimento.
*/

#include <stdio.h>
#include <stdlib.h>

// indicamos o parametro com * para indicar ponteiro
void imprimir(int *num)
{
    printf("Idade na funcao (*num): %d\n", *num);
    *num = 100;
}

int main()
{
    int idade = 20;

    // passamos o endereco da variavel
    imprimir(&idade);

    printf("Idade na main apos funcao (*num = 100): %d\n", idade);

    system("pause");
    return 0;
}
