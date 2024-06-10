#include <stdio.h>
#include <stdlib.h>

int a = 0, b = 0, soma = 0; // variaveis globais para a multiplicacao russa

int russa(int a, int b, int soma) // funcao recursiva para a multiplicacao russa
{
    if (a < 1) // retorna a soma quando a divisao de A por 2 for menor que 0;
    {
        return soma;
    }
    else
    {
        printf("\n%2d - %2d ", a, b); // imprime colunas

        if (a % 2 != 0 || a == 1)
        {
            soma += b; // soma valores de B que estao ao lado de valores impares de A
            printf("- %2d", b);
        }

        a /= 2;
        b *= 2;

        printf("\n");

        return (russa(a, b, soma));
    }
}

int main()
{
    printf("Informe o numero A: "); // leitura de A
    scanf("%d", &a);
    printf("Informe o numero B: "); // leitura de B
    scanf("%d", &b);

    // chamada da funcao recursiva para a multipliacao
    printf("Multiplicacao Russa: %d\n", russa(a, b, soma));

    system("pause");
    return 0;
}