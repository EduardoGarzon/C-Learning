#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a = 10, b = 100;
  float c = 10.5, d = 100.5;

  printf("Testando operadores que incrementam e decrementam\n");
  printf("Valores iniciais de a=%d, b=%d, c=%f, d=%f\n", a, b, c, d);

  printf("Prefixado: incrementa e depois usa o conteúdo\n");
  printf("++a = %d \n", ++a);
  printf("--b = %d \n", --b);
  printf("++c = %f \n", ++c);
  printf("--d = %f \n", --d);

  printf("Posfixado: usa o conteúdo e depois incrementa\n");
  printf("a++ = %d \n", a++);
  printf("b-- = %d \n", b--);
  printf("c++ = %f \n", c++);
  printf("d-- = %f \n", d--);

  printf("Depois da operação\n");
  printf("a++ = %d \n", a);
  printf("b-- = %d \n", b);
  printf("c++ = %f \n", c);
  printf("d-- = %f \n", d);

  system("pause");
  return 0;
}
