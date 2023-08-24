/*
11. Faça um programa que leia n linhas e as decodifique utilizando a tabela de substituição
de caracteres a seguir. Imprima, para cada linha lida, a linha no formato original e sua
decodificação.

Caractere existente         z y w k b d f
Caractere a ser substituído A E O T M N P
Testar o programa com as linhas a seguir:
Kydhz kybfw fzrz w quy y’ bzis ibfwrkzdky fzrz vwcy.
Kydhz kybfw fzrz yskzr cwb zquylys z quyb vwcy zbz.
Kydhz kybfw fzrz swdhzr.
Kydhz kybfw fzrz vivyr ub swdhw...
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char linha[60] = {"Kydhz kybfw fzrz w quy y bzis ibfwrkzdky fzrz vwcy."}; // cada vetor é uma linha de texto
    char linhab[60] = {"Kydhz kybfw fzrz yskzr cwb zquylys z quyb vwcy zbz."};
    char linhac[60] = {"Kydhz kybfw fzrz swdhzr."};
    char linhad[60] = {"Kydhz kybfw fzrz vivyr ub swdhw... "};
    char cod[8] = {'z', 'y', 'w', 'k', 'b', 'd', 'f'}; // vetor com os caracteres de criptografia
    char res[8] = {'a', 'e', 'o', 't', 'm', 'n', 'p'}; // vetor com as letras respectivas as letras de criptografia

    for (int i = 0; i <= strlen(cod); i++) // vai ler o vetor de criptografia
    {
        for (int x = 0; x <= strlen(linha); x++) // se o caracter do indice for igual ao caracter da criptografia ele substitui pela letra correspondete do vetor res, para todos as linhas.
        {
            if (tolower(linha[x]) == cod[i])
            {
                linha[x] = res[i];
            }
            if (tolower(linhab[x]) == cod[i])
            {
                linhab[x] = res[i];
            }
            if (tolower(linhac[x]) == cod[i])
            {
                linhac[x] = res[i];
            }
            if (tolower(linhad[x]) == cod[i])
            {
                linhad[x] = res[i];
            }
        }
    }

    printf("%s\n", linha);
    printf("%s\n", linhab);
    printf("%s\n", linhac);
    printf("%s", linhad);

    return 0;
}
