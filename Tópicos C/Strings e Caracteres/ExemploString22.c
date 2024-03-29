/*
    Solicite ao usuário que informe seu numero de celular,
    sendo DDD+numero (sem digito e sem espaço).
    Informe a qual região o código pertence.

    Considere:
        i.   45 – Cascavel;
        ii.  41 – Curitiba;
        iii. 21 – Rio de Janeiro;
        iv.  51 – Porto Alegre;
        v.   67 – Mato Grosso do Sul;
        vi.  63 – Tocantins.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char numero[15];

    printf("Informe seu DDD+numero sem espacos e sem digito: ");
    fgets(numero, 15, stdin); // Lendo o DDD+numero

    // testes de regioes de cada DDD
    if (numero[0] == '4' && numero[1] == '5')
    {
        printf("Regiao de Cascavel.\n");
    }
    else if (numero[0] == '4' && numero[1] == '1')
    {
        printf("Regiao de Curitiba.\n");
    }
    else if (numero[0] == '2' && numero[1] == '1')
    {
        printf("Regiao de Rio de Janeiro.\n");
    }
    else if (numero[0] == '5' && numero[1] == '1')
    {
        printf("Regiao de Porto Alegre.\n");
    }
    else if (numero[0] == '6' && numero[1] == '7')
    {
        printf("Regiao de Mato Grosso do Sul.\n");
    }
    else if (numero[0] == '6' && numero[1] == '3')
    {
        printf("Regiao de Tocantins.\n");
    }
    else
    {
        printf("Regiao nao identificada.\n");
    }

    system("pause");
    return 0;
}