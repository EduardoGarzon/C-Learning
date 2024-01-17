/*
    Implemente em linguagem de programação C um algoritmo que
    calcule o valor médio de um conjunto de n números reais.
    O algoritmo deverá calcular a soma dos números informados
    e, quando o número fornecido pelo usuário for zero,
    apresentar o valor da média.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero, soma;
    int cont;

    cont = 0;

    while (numero != 0)
    {
        printf("Informe um numero:  ");
        scanf("%f", &numero);

        soma += numero;

        if (numero != 0)
        {
            cont = cont + 1;
        }
    }
    soma = (soma / cont);

    printf("\n");
    printf("Media dos numeros informados: %0.1f\n", soma);

    system("pause");
    return 0;
}