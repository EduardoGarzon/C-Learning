/* 3. Faça uma função para verificar se um número é positivo ou negativo.
Sendo que o valor de retorno será 1 se positivo, -1 se negativo e 0 se for
igual a 0. */

#include <stdio.h>

int verificar(int numero, int flag)
{
    if (numero > 0)
    {
        flag = 1;
    }
    else if (numero < 0)
    {
        flag = -1;
    }
    else
    {
        flag = 0;
    }
    return flag; // funcao retorna para main o valor da flag de acordo com os testes acima
}

int main()
{

    int numero = 0; // variavel que vai receber o numero informado
    int flag = 0;   // flag que vai determinar os resultados

    printf("Informe um numero: ");
    scanf("%d", &numero);

    flag = verificar(numero, flag); // chamada que verifica o numero informado

    if (flag == 1) // retornando a flag da funcao vai testar o valor conforme o enunciado
    {
        printf("\nO numero e positivo.");
    }
    else if (flag == -1)
    {
        printf("\nO numero e negativo.");
    }
    else
    {
        printf("\nO numero e igual a zero.");
    }

    return 0;
}