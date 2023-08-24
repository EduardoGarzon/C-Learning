/* Altere o programa anterior, viabilizando que a verificação da operação a ser realizada
seja efetuada no início do programa (após a linha 7).*/

#include <stdio.h>

int main()
{
    char opera;
    int n1, n2;
    printf("Qual operação deseja realizar? Selecione uma (+, -, *, /): ");
    scanf("%c", &opera);
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
    return 0;
} 