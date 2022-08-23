/*
4. Faça um programa que crie um arquivo TEXTO em disco, com o nome
“dados.txt”, e escreva neste arquivo em disco uma contagem que vá de
1 até 100, com um número em cada linha.
*/

#include <stdio.h>

int main()
{
    FILE *arquivo;
    arquivo = fopen("dados.txt", "w"); // abertura de arquivo
    if (arquivo == NULL)               // teste de abertura de arquivo
    {
        printf("Erro na abertura de arquivo.\n");
    }
    for (int i = 0; i < 101; i++)
    {
        fprintf(arquivo, "%d\n", i); // inserindo contagem de 0 ate 100
    }
    fclose(arquivo);
    return 0;
}