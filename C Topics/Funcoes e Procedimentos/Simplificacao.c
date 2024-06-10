/*
    Faça uma função chamada ‘simplifica’ que recebe como parâmetro o
    numerador e o denominador de uma fração. Esta função deve simplificar ao
    máximo a fração recebida.
*/

#include <stdio.h>
#include <stdlib.h>

void simplificar(int numerador, int denominador)
{
    int flag = 0;     // flag para contagem das possibilidades de simplificacoes
    int i = 2;        // indice dos numeros que serao testados para simplificar
    while (flag != 8) // repete enquanto todas as possibilidades de 2 ate 9 forem possiveis para simplificar os numeros
    {
        if (numerador % i == 0 && denominador % i == 0) // se o resto da divisao for == 0 em ambos, a divisao e realizada e o i e a flag voltam do inicio novamente para reiniciar o teste
        {
            numerador /= i;
            denominador /= i;
            i = 2;
            flag = 0;
        }
        else
        {
            i++; // caso o teste seja falso entao o i parte para o proximo numero a ser testado e a flag e incrementada
            flag++;
        }
    }
    printf("Numerador: %d\n", numerador);
    printf("Denominador: %d\n", denominador);
}

int main()
{
    int numerador = 0, denominador = 0; // variaveis para numerador de denominador

    printf("Informe o numerador: ");
    scanf("%d", &numerador);
    printf("Informe o denominador: ");
    scanf("%d", &denominador);
    printf("\n");

    simplificar(numerador, denominador); // chamada da funcao que vai simplificar ao maximo a fracao

    system("pause");
    return 0;
}