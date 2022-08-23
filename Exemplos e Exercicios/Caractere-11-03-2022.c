#include <stdio.h>
/* atribui A tanto pelo caracter quanto pelo número ASCII */
int main()
{
  char c1, c2;
  printf("Atribui o caractere A: \n");
  c1 = 'A';
  c2 = 65; // ASCII
  printf("%c %c", c1, c2);
  return 0;
}
