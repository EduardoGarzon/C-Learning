#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia, mes, ano;
} Aniversario;

typedef struct
{
    Aniversario data;
    char nome[100];
} Pessoa;

int main()
{
    Pessoa p;
    Aniversario a;

    printf("%lld Bytes\n", sizeof(p));
    printf("%lld Bytes\n", sizeof(a));

    system("pause");
    return 0;
}