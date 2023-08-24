/*
Procedimento para imprimir uma matriz - Nao tem retorno
Funcao para somar uma linha de uma matriz - Tem retorno
*/

#include <stdio.h>
#include <stdlib.h> // rand()
#include <time.h>   // srand(time(NULL))

int tamanho_matriz = 5; // variavel global
// int matriz[5][5] declarando a matriz global nao precisamos passar ela como parametro

void imprimir_matriz(int matriz[][5])
{
    for (int i = 0; i < tamanho_matriz; i++)
    {
        printf("[ ");
        for (int j = 0; j < tamanho_matriz; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
        printf(" ]\n");
    }
}

int somar_linha_Matriz(int matriz[][5], int i)
{
    int soma = 0;
    for (int j = 0; j < tamanho_matriz; j++)
        soma += matriz[i][j]; // soma os elementos de cada coluna da linha atual

    return soma;
}

int somar_coluna_Matriz(int matriz[][5], int j)
{
    int soma = 0;
    for (int i = 0; i < tamanho_matriz; i++)
        soma += matriz[i][j]; // soma os elementos de cada coluna da coluna atual

    return soma;
}

int main()
{
    int matriz[5][5]; // matriz local

    srand(time(NULL)); // gerador de numeros aleatorios com semente baseada no tempo atual

    // atribuindo valores aleatorios de 0 a 9 para a matriz
    for (int i = 0; i < tamanho_matriz; i++)
        for (int j = 0; j < tamanho_matriz; j++)
            matriz[i][j] = rand() % 10;

    // procedimento imprimindo a matriz
    imprimir_matriz(matriz);

    // funcao para somar cada linha da matriz
    // parametros: matriz e linha atual
    printf("\n");
    for (int i = 0; i < tamanho_matriz; i++)
        printf("Soma linha %d: %d\n", i, somar_linha_Matriz(matriz, i));

    // funcao para somar cada coluna da matriz
    // parametros: matriz e coluna atual
    printf("\n");
    for (int j = 0; j < tamanho_matriz; j++)
        printf("Soma coluna %d: %d\n", j, somar_coluna_Matriz(matriz, j));

    return 0;
}