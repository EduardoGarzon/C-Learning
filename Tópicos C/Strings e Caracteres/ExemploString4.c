/*
    sizeof retorna a quantidade de bytes de um objeto ou tipo.

    Não é adequado para ver o tamanho de uma string.

    Se a string está representada por um ponteiro,
    o tamanho será do ponteiro e não do texto.

    Se for por um array mostrará sempre um resultado equivocado,
    pois pode considerar o caractere nulo,
    ou pode ser que a string tenha sido atribuída e
    tenha ultrapassado o limite do array.

    strlen() é uma função contida em string.h que conta quantos caracteres,
    que equivalem a bytes, em uma sequência passada para ela
    através de uma referência até achar um caractere nulo \0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char teste[10] = "carlos";

    printf("%s | sizeof: %lld | strlen: %lld\n", teste, sizeof(teste), strlen(teste));
    // strlen == 4 pois possui 4 caracteres
    // sizeof == 10 pois a string armazena ate 10 caracteres, 1 byte cada

    system("pause");
    return 0;
}