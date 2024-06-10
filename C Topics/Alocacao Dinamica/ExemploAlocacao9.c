/*
    Faça um programa que pergunte ao usuário
    quantos valores ele deseja armazenar em um vetor de double.

    Depois use a função MALLOC para reservar (alocar) o espaço de memória
    de acordo com o especificado pelo usuário.

    Use neste vetor dinâmico o preenchimento com números aleatórios
    (usando a função rand) entre 0 e 100.

    Exiba na tela os valores armazenados no vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int tamanho = 0; // tamanho do vetor
    double *vetor;   // ponteiro
    int i = 0;       // indice e laco de repeticao

    printf("Informe o tamanho do componente vetor: "); // lendo o tamanho do vetor
    scanf("%d", &tamanho);

    vetor = malloc(tamanho * sizeof(double)); // alocando o vetor

    srand(time(NULL)); // semente

    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 100; // atribuindo valores aleatorios
        printf("[%d] ");         // imprimindo o vetor
    }

    free(vetor); // liberando espaco

    system("pause");
    return 0;
}