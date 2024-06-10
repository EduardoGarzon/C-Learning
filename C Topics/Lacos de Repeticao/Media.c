#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n = 4, soma = 0;
  float final;
  
  for (int i = 0; i <= n; i++)
  {
    soma++;
  }
  
  final = soma / n;
  
  printf("Valor de soma = %d\n", soma);
  printf("Resultado Media = %f\n", final);
  
  system("pause");
  return 0;
}
