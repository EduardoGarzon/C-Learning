/*
5. Faça um programa que leia o arquivo “vogais.txt” e mostre na tela
quantas letras são vogais e quantas são consoantes.
*/
#include <stdio.h>
int main()
{
    char vogais[6] = {'a', 'e', 'i', 'o', 'u'}; // vetor de vogais
    int vog = 0, cons = 0, flag = 0;
    FILE *arquivo;
    arquivo = fopen("vogais.txt", "r"); // abertura de arquivo
    if (arquivo == NULL)                // testando abertura do arquivo
    {
        printf("Erro na abertura do arquivo.\n");
    }
    while (!feof(arquivo)) // repete ate o fim do arquivo
    {
        char caractere = fgetc(arquivo);
        for (int i = 0; i < 6; i++)
        {
            flag = vog;
            if (caractere == vogais[i]) // compara o caractere do arquivo com o vetor de vogais
            {
                vog++;
                break;
            }
        }
        if (flag == vog) // consoante se flag == contador atual para vogais
        {
            cons++;
        }
    }
    printf("Vogais encontradas: %d\n", vog);
    printf("Consoantes encontradas: %d\n", cons);
    fclose(arquivo);
    return 0;
}