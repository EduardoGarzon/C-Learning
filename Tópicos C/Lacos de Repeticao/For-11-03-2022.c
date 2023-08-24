#include <stdio.h>

int main(void)
{
  int n, i, soma;
  float final;
  n = 4;
  soma = 0;
  for (i = 1; i < n; i++)
  {
    soma = soma + 1;
  }
  final = soma / (n - 1);
  printf("Valor de soma= %d\n", soma);
  printf("Resultado= %f", final);
  return 0;
}
