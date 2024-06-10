#include <stdio.h>
#include <stdlib.h>

int main()
{
  short a;
  long b;
  long long c;
  long double d;

  printf("Exemplos de quantidade de bytes utilizados pelos tipos short e long:\n");
  printf("Bytes de short = %lu bytes\n", sizeof(a));
  printf("Bytes de long = %lu bytes\n", sizeof(b));
  printf("Bytes de long long = %lu bytes\n", sizeof(c));
  printf("Bytes de long double= %lu bytes\n", sizeof(d));

  system("pause");
  return 0;
}
