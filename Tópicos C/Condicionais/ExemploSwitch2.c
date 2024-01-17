/*
    Exemplo de utilizacao da estrutura de selecao switch case.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char opera;
    int n1, n2;

    printf("Qual operação deseja realizar? Selecione uma (+, -, *, /): ");
    scanf("%c", &opera);
    getchar();

    switch (opera)
    {
    case '+':
        printf("Digite o primeiro número a operar: ");
        scanf("%d", &n1);

        printf("Digite o segundo número a operar: ");
        scanf("%d", &n2);

        printf("%d + %d = %d", n1, n2, n1 + n2);

        break;
    case '-':
        printf("Digite o primeiro número a operar: ");
        scanf("%d", &n1);

        printf("Digite o segundo número a operar: ");
        scanf("%d", &n2);

        printf("%d - %d = %d", n1, n2, n1 - n2);

        break;
    case '*':
        printf("Digite o primeiro número a operar: ");
        scanf("%d", &n1);

        printf("Digite o segundo número a operar: ");
        scanf("%d", &n2);

        printf("%d * %d = %d", n1, n2, n1 * n2);

        break;
    case '/':
        printf("Digite o primeiro número a operar: ");
        scanf("%d", &n1);

        printf("Digite o segundo número a operar: ");
        scanf("%d", &n2);

        printf("%d / %d = %d", n1, n2, n1 / n2);

        break;
    // Se não for nenhuma das opções +, -, *, /
    default:
        printf("Opção incorreta. Opte por +, -, * ou /n");
    }

    system("pause");
    return 0;
}