/*
    Faça um programa que leia n linhas e
    as decodifique utilizando a tabela de substituição de caracteres a seguir
    .
    Imprima, para cada linha lida, a linha no formato original e sua decodificação.

    Caractere existente         z y w k b d f
    Caractere a ser substituído A E O T M N P

    Testar o programa com as linhas a seguir:
        Kydhz kybfw fzrz w quy y’ bzis ibfwrkzdky fzrz vwcy.
        Kydhz kybfw fzrz yskzr cwb zquylys z quyb vwcy zbz.
        Kydhz kybfw fzrz swdhzr.
        Kydhz kybfw fzrz vivyr ub swdhw...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // cada vetor é uma linha de texto
    char linha[60] = {"Kydhz kybfw fzrz w quy y bzis ibfwrkzdky fzrz vwcy."};
    char linhab[60] = {"Kydhz kybfw fzrz yskzr cwb zquylys z quyb vwcy zbz."};
    char linhac[60] = {"Kydhz kybfw fzrz swdhzr."};
    char linhad[60] = {"Kydhz kybfw fzrz vivyr ub swdhw... "};
    char cod[8] = {'z', 'y', 'w', 'k', 'b', 'd', 'f'}; // caracteres de criptografia
    // letras respectivas as letras de criptografia
    char res[8] = {'a', 'e', 'o', 't', 'm', 'n', 'p'};

    strlwr(linha);
    strlwr(linhab);
    strlwr(linhac);
    strlwr(linhad);

    for (int i = 0; i <= (int)strlen(cod); i++) // ler o vetor de criptografia
    {
        // se o caracter do indice for igual ao caracter da criptografia,
        // substitui pela letra correspondete do vetor res, para todos as linhas.
        for (int x = 0; x <= (int)strlen(linha); x++)
        {
            if (linha[x] == cod[i])
            {
                linha[x] = res[i];
            }
            if (linhab[x] == cod[i])
            {
                linhab[x] = res[i];
            }
            if (linhac[x] == cod[i])
            {
                linhac[x] = res[i];
            }
            if (linhad[x] == cod[i])
            {
                linhad[x] = res[i];
            }
        }
    }

    printf("%s\n", linha);
    printf("%s\n", linhab);
    printf("%s\n", linhac);
    printf("%s\n", linhad);

    system("pause");
    return 0;
}
