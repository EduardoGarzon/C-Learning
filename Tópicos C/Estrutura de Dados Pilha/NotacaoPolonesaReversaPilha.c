/*
    Resolvendo expressao em notacao pos-fixa na PILHA.
    A operacao matematica ocorre da esquerda para a direita.
    A operacao matematica esta sempre a direita dos numeros.

    Exemplo:
    5 3 2 + * 4 / 6 -
    5 5 * 4 / 6 -
    2 5 4 / 6 -
    6.25 6 -
    0.25
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    float valor; // cada numero da notacao
    struct no *proximo;
} No;

No *empilhar(No *pilha, float valor)
{
    No *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = valor;
        novo->proximo = pilha;

        return novo;
    }
    else
    {
        printf("Erro na alocacao!\n");

        return NULL;
    }
}

No *desempilhar(No **pilha)
{
    No *remover = NULL;

    if (*pilha)
    {
        remover = *pilha;
        *pilha = remover->proximo;

        return remover;
    }
    else
    {
        printf("Pilha Vazia!\n");

        return NULL;
    }
}

// retorna operacao realizada
float operacao(float a, float b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '/':
        return a / b;
        break;
    case '*':
        return a * b;
        break;

    default:
        return 0.0;
        break;
    }
}

float resolver_expressao(char notacao[])
{
    char *pt;
    float numero;
    No *n1, *n2, *pilha = NULL;

    pt = strtok(notacao, " "); // divide a string e tokens delimitador por " "

    while (pt) // enquanto tiver caracteres
    {
        // se for uma operacao matematica opera os dois numeros anteriores ao simbolo
        if (pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*')
        {
            // desempilha 2 numeros
            n1 = desempilhar(&pilha);
            n2 = desempilhar(&pilha);

            // envia para o calculo os dois numeros + a operaco lida
            numero = operacao(n2->valor, n1->valor, pt[0]);

            // empilha o resultado
            pilha = empilhar(pilha, numero);

            free(n1);
            free(n2);
        }
        else
        {
            // convertendo para a string para float
            numero = strtof(pt, NULL);
            pilha = empilhar(pilha, numero);
        }

        pt = strtok(NULL, " "); // limpa token
    }

    // ao final da expressao, sem mais caracteres lidos
    n1 = desempilhar(&pilha);
    numero = n1->valor;

    free(n1);

    return numero;
}

int main()
{
    char exp[50] = {"5 3 2 + * 4 / 6 -"};

    printf("Resultado de %s: \n", exp);
    printf("%f\n", resolver_expressao(exp));

    system("pause");
    return 0;
}