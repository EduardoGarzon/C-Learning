/*
  Atribuindo A tanto pelo caracter quanto pelo número ASCII.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char c1, c2;

  printf("Atribui o caractere A: \n");
  c1 = 'A'; // Char
  c2 = 65;  // ASCII

  printf("Char: %c | ASCII: %c\n", c1, c2);

  system("pause");
  return 0;
}
