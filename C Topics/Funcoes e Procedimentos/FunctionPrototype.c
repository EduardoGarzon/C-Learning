/*
    Prototipos de funcoes sao funcoes declaradas sem o corpo.
    Sao assinaturas das funcoes.
    Garante que a chamada da funcao esteja sendo feita com os parametros corretos.
    Caso os parametros estejam incorretos um erro deve ocorrer, nao compilando.
    Normalmente as assinaturas ficam em header files.
*/

#include <stdio.h>
#include <stdlib.h>

void hello(char[]);

int main()
{
    char nome[] = "Eduardo";

    hello(nome);

    system("pause");
    return 0;
}

void hello(char nome[])
{
    printf("Ola %s seja bem vindo!\n");
}