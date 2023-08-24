/* 3. Solicite ao usuário que informe seu numero de celular, sendo DDD+numero (sem digito e sem espaço). Informe a qual região o código pertence.
a. Considere:
i. 45 – Cascavel;
ii. 41 – Curitiba;
iii. 21 – Rio de Janeiro;
iv. 51 – Porto Alegre;
v. 67 – Mato Grosso do Sul;
vi. 63 – Tocantins.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char numero[15];

    printf("Informe seu DDD+numero sem espacos e sem digito: ");
    fgets(numero, 15, stdin); // Lendo o DDD+numero

    // testes de regioes de cada DDD
    if (numero[0] == '4' && numero[1] == '5')
    {
        printf("Regiao de Cascavel.");
    }
    else if (numero[0] == '4' && numero[1] == '1')
    {
        printf("Regiao de Curitiba.");
    }
    else if (numero[0] == '2' && numero[1] == '1')
    {
        printf("Regiao de Rio de Janeiro.");
    }
    else if (numero[0] == '5' && numero[1] == '1')
    {
        printf("Regiao de Porto Alegre.");
    }
    else if (numero[0] == '6' && numero[1] == '7')
    {
        printf("Regiao de Mato Grosso do Sul.");
    }
    else if (numero[0] == '6' && numero[1] == '3')
    {
        printf("Regiao de Tocantins.");
    }
    else
    {
        printf("Regiao nao identificada.");
    }

    return 0;
}