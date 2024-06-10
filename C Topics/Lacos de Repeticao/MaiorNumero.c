/*
    Leia X valores inteiros. Apresente então o maior valor lido e sua posição
    (sua ordem na sequência) dentre os X valores lidos.
    Se houver repetição do número maior,
    informar sua última posição.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int resposta = 1, numero = 0, cont = 0, maior = 0, posicao = 0, qtd = 0;

    while (resposta == 1)
    {
        printf("Informe um numero inteiro positivo: ");
        scanf("%d", &numero);
        cont++;

        if (numero >= maior)
        {
            maior = numero;
            posicao += cont;
        }

        printf("\n");
        printf("Continuar? [0 / 1]: ");
        scanf("%d", &resposta);
    }

    printf("\n");
    printf("Maior numero da sequencia informada: %d\n", maior);
    printf("Posicao do maior elemento: %d\n", posicao);

    system("pause");
    return 0;
}