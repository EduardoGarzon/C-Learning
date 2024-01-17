/*
    Crie um programa que:
        a. Solicite o primeiro nome do pai e mãe;
        b. Solicite o sobrenome da família;
        c. Solicite o nome de um filho;

    Na sequencia apresente na tela o nome de toda a família completa.
    (nome + sobrenome).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char pai[100], mae[100], filho[100], sobrenome[100];

    printf("Informe o nome do pai: ");
    gets(pai);
    getchar();

    printf("Informe o nome da mae: ");
    gets(mae);
    getchar();

    printf("Informe o nome do filho: ");
    gets(filho);
    getchar();

    printf("Informe o sobrenome da familia: ");
    gets(sobrenome);
    getchar();
    
    strcat(pai, " ");
    strcat(pai, sobrenome);

    strcat(mae, " ");
    strcat(mae, sobrenome);

    strcat(filho, " ");
    strcat(filho, sobrenome);

    printf("%s\n", pai);
    printf("%s\n", mae);
    printf("%s\n", filho);

    system("pause");
    return 0;
}