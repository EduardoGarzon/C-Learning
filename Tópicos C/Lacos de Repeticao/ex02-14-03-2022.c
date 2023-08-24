/* 02) Imprimir todos os números compreendidos entre de 1 a 300, de 3 em 3, 
apresentandoos, lado a lado. 14/03/2022 */

#include <stdio.h>

int main()
{
    int numero;

    printf("Contagem de 1 ate 300 passo 3: \n");
    for (numero = 100; numero <= 300; numero += 3)
    {
        printf("\n%i", numero);
    }
    return 0;
}