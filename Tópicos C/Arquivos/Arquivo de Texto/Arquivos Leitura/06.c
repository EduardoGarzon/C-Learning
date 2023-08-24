/*
6. Faça um programa que receba do usuário um arquivo texto. Crie outro
arquivo texto contendo o texto do arquivo de entrada, mas com as
vogais substituídas por „*‟.
*/
#include <stdio.h>
int main()
{
    char vogais[6] = {'a', 'e', 'i', 'o', 'u'};
    char caractere;
    int flag;
    FILE *texto, *copia;
    texto = fopen("textoex06.txt", "r"); // abertura de arquivo texto
    copia = fopen("copiaex06.txt", "w"); // abertura do arquivo copia
    if (texto == NULL || copia == NULL)  // testando abertura dos arquivos
    {
        printf("Erro na abertura de arquivo.\n");
    }
    while (!feof(texto))
    {
        flag = 0;
        caractere = fgetc(texto);
        for (int i = 0; i < 6; i++) // verificando se é vogal
        {
            if (caractere == vogais[i])
            {
                fputc('*', copia); // substitui se for vogal
                flag = 1;          // flag muda
                break;
            }
        }
        if (flag == 0) // flag nao mudou
        {
            fprintf(copia, "%c", caractere); // insere o caractere normal
        }
    }
    fclose(texto);
    fclose(copia);
    return 0;
}