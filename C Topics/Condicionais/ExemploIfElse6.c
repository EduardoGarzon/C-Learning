#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num1, num2, num3, maior, menor;

  maior = 0;
  menor = 9999;

  printf("Informa o maior e o menor de três números: \n");
  printf("Digite o primeiro número ");
  scanf("%d", &num1);

  if (num1 > maior)
    maior = num1;
  if (num1 < menor)
    menor = num1;

  printf("Digite o segundo número ");
  scanf("%d", &num2);

  if (num2 > maior)
    maior = num2;
  if (num2 < menor)
    menor = num2;
  
  printf("Digite o terceiro número ");
  scanf("%d", &num3);
  
  if (num3 > maior)
    maior = num3;
  if (num3 < menor)
    menor = num3;
  
  printf("O maior valor é %d o menor valor é %d\n", maior, menor);
  
  system("pause");
  return 0;
}
