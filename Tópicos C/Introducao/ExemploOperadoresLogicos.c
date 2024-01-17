#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a = 5, b = 5, c = 10, result;

  printf("Testando operadores compostos a=%d, b=%d, c=%d e result=%d\n", a, b, c, result);
  printf("Sendo &&=E - ||=OU - !=Não");
  printf("Retorna 0 quando falso");

  result = (a == b) && (c > b);
  printf("(a == b) && (c > b) is %d \n", result);

  result = (a == b) && (c < b);
  printf("(a == b) && (c < b) is %d \n", result);

  result = (a == b) || (c < b);
  printf("(a == b) || (c < b) is %d \n", result);

  result = (a != b) || (c < b);
  printf("(a != b) || (c < b) is %d \n", result);

  result = !(a != b);
  printf("!(a != b) is %d \n", result);

  result = !(a == b);
  printf("!(a == b) is %d \n", result);

  system("pause");
  return 0;
}
