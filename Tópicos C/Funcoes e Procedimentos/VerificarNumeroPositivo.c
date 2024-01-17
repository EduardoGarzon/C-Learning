/*
    Faça uma função para verificar se um número é positivo ou negativo.
    Sendo que o valor de retorno será 1 se positivo, -1 se negativo
    e 0 se for igual a 0.
*/

#include <stdio.h>
#include <stdlib.h>

int verificar(int numero)
{
    int flag = 0;

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
    printf("\n");

    flag = verificar(numero); // chamada que verifica o numero informado

    if (flag == 1) // retornando a flag da funcao vai testar o valor conforme o enunciado
    {
        printf("O numero e positivo.\n");
    }
    else if (flag == -1)
    {
        printf("O numero e negativo.\n");
    }
    else
    {
        printf("O numero e igual a zero.\n");
    }

    system("pause");
    return 0;
}