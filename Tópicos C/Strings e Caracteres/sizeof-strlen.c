/* 
sizeof retorna a quantidade de bytes de um objeto ou tipo. Não é adequado para ver o tamanho de uma string. Se a string está representada por um ponteiro, o tamanho será do ponteiro e não do texto. Se for por um array mostrará sempre um resultado equivocado, pois pode considerar o caractere nulo, ou pode ser que a string tenha sido atribuída e tenha ultrapassado o limite do array.

strlen() é uma função contida em string.h que conta quantos caracteres - que equivalem a bytes - em uma sequência passada para ela através de uma referência até achar um caractere nulo \0.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char teste[10] = "luiz";
    printf("%s | sizeof: %d | strlen: %d", teste, sizeof(teste), strlen(teste));

    return 0;
}