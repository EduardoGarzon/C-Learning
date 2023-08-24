/* Utilizando a estrutura “para/passo”, implemente em linguagem de programação C um algoritmo
para calcular e escrever a soma dos números ímpares compreendidos entre 100 e 200. 14/03/2022 */

#include <stdio.h>

int main()
{
    int numero, soma;

    for (numero = 100; numero <= 200; numero++)
    {
        if ((numero % 3) == 0)
        {
            soma = soma + numero;
        }
    }
    printf("Soma dos numeros impares entre 100 e 200: %i", soma);
    return 0;
}
