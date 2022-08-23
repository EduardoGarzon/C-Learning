/*
1. Crie uma função recursiva que receba um número inteiro positivo N e
calcule o somatório dos números de 1 a N.
*/

#include <stdio.h>

int somatorio(numero) // funcao recursiva que soma os numeros de 1 ate o numero infomado
{
    if (numero == 1)
    {
        return 1;
    }
    else
    {
        return (numero + somatorio(numero - 1));
    }
}

int main()
{
    int numero = 0;                        // variavel para o numero inteiro
    printf("Informe um numero inteiro: "); // leitura do numero inteiro
    scanf("%d", &numero);

    int soma = somatorio(numero); // chamada da funcao recursiva

    printf("Soma dos elementos de 1 ate %d: %d", numero, soma); // imprimindo na tela os resultados

    return 0;
}