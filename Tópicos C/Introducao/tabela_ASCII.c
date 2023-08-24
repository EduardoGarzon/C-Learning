#include <stdio.h>
#include <locale.h> // inclusao de um arquivo de interface

int main()
{
    /*
        imprimir um caractere com %d retorna seu valor na tabela ASCII

        o tipo char ocupa 1 byte (8 bits) logo, valores de -128 ate 127

        a TABELA ASCII serve para mapeamente de caracteres e numeros

        de 0 ate 127 sao representados os caracteres sem acentuacao

        a tabela ASCII estendida utiliza o unsigned assim os valores podem ser representados
        de 0 ate 255, assim a maioria dos caracteres acentuados podem ser representados
    */

    // para utilizar e configurar tabela ASCII
    setlocale(LC_ALL, NULL);         // padrao da linguagem C, 0 ate 127, ASCII padrao
    setlocale(LC_ALL, "");           // padrao do sistema operacional
    setlocale(LC_ALL, "Portuguese"); // portugues brasileiro, 0 ate 255, tabela ASCII estendida

    return 0;
}
