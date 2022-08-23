/* 06) Leia X valores inteiros. Apresente então o maior valor lido e sua posição
(sua ordem na sequência) dentre os X valores lidos. Se houver repetição do número maior,
informar sua última posição (URI adaptado). 14/03/2002 */

#include <stdio.h>

int main()
{
    int resposta, numero, cont, maior, posicao, qtd;

    resposta = 1;
    cont = 0;
    maior = 0;
    qtd = 0;
    posicao = 0;
    while (resposta == 1)
    {
        printf("Informe um numero inteiro positivo: ");
        scanf("%i", &numero);
        cont++;

        if (numero >= maior)
        {
            maior = numero;
            posicao += cont;
        }

        printf("\nContinuar? [0 / 1]: ");
        scanf("%i", &resposta);
    }
    printf("\nMaior numero da sequencia informada: %i", maior);
    printf("\nPosicao do maior elemento: %i", posicao);
    return 0;
}