/*1. Faça um programa que lê um número N e sorteia N números inteiros
(entre 0 e 100), gravando todos em um arquivo texto (randômico.txt). A
primeira linha do arquivo deverá conter a quantidade de números, e os
números gravados deverão ser separados por virgula.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // gerando valores aleatorios
    int valor = 0;
    FILE *arquivo;
    arquivo = fopen("random0-100.txt", "w+"); // abertura de arquivo para leitura e escrita
    if (arquivo == NULL)                      // teste na abertura do arquivo
    {
        printf("Erro na abertura de arquivo.\n");
    }
    printf("Informe um valor: "); // leitura do valor
    scanf("%d", &valor);
    fprintf(arquivo, "Total de numeros aleatorios: %d\n", valor);
    for (int i = 0; i < valor; i++)
    {
        fprintf(arquivo, "%d, ", rand() % 100); // inserindo valores aleatorios
    }
    fclose(arquivo);
    return 0;
}