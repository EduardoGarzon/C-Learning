// Exemplos de formatacao de saida.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        %.1 -> decimal precision
        %1  -> minimum field width
        %- -> left align
    */

    float A = 10.1234, B = 20.1234, C = 30.1234;

    printf("Formatando variáveis reais: \n");

    printf("%.2f\n", A);
    printf("%1f\n", B);
    printf("%8.3f\n", C);

    system("pause");
    return 0;
}
