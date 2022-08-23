// testando exemplo com typedef para agrupura um novo tipo de dado

#include <stdio.h>

typedef struct
{
    int idade;
    char nome[10];
}cadastro;

int main()
{
    cadastro pessoa1;

    printf("Informe sua idade: ");
    scanf("%d", &pessoa1.idade);
    fflush(stdin);
    printf("Informe seu nome: ");
    gets(pessoa1.nome);

    printf("Informe sua idade: %d\n", pessoa1.idade);
    printf("Informe seu nome: %s", pessoa1.nome);

    return 0;
}