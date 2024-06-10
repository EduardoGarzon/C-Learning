#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x, i;
  int soma = 0;

  printf("Faz a soma de x números a partir de 1.\n");
  printf("Até qual número vc quer somar?\n");
  scanf("%d", &x);
  
  i = 1;
  while (i <= x)
  {
    printf("Número a somar: %d\n", i);
    soma = soma + i;
    i++;
  }
  
  printf("Soma = %d\n", soma);
  
  system("pause");
  return 0;
}
