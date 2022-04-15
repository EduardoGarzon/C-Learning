#include <stdio.h>
int main()
{
  int nota1, nota2, nota3;
  int media;
  printf("Faz a média entre três notas: \n");
  printf("Digite a primeira nota ");
  scanf("%d", &nota1);
  printf("Digite a segunda nota ");
  scanf("%d", &nota2);
  printf("Digite a terceira nota ");
  scanf("%d", &nota3);
  media = (nota1 + nota2 + nota3) / 3;
  printf("A média é %3.2f\n", media);
  return 0;
}
