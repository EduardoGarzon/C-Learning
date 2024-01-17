/*
    Faça um programa que leia um número N e:
    • Crie dinamicamente e leia um vetor de inteiro de N posições;
    • Leia um número inteiro X conte e mostre os múltiplos 
    desse número que existem no vetor.
    
    Ex: 35 é múltiplo de 7, pois 35 é igual a 7 multiplicado pelo número inteiro 5.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 0, valor = 0, i = 0;
    int *vetor;

    printf("Informe um numero para alocar: ");
    scanf("%d", &numero);

    vetor = malloc(numero * sizeof(int)); // alocando a variavel com o numero informado
    
    printf("\n");
    for (i = 0; i < numero; i++)
    {
        printf("Informe um valor para [%d]: ", i); // lendo valores para o vetor alocado
        scanf("%d", &vetor[i]);
    }

    printf("\n");
    printf("Informe um numero: "); // lendo um valor para verificar se existe seu multiplo
    scanf("%d", &valor);

    printf("Valores multiplos do numero no vetor: \n");
    for (i = 0; i < numero; i++)
    {
        // verifica se o numero do vetor e multiplo do valor informado
        if (((vetor[i] / valor) * valor) == vetor[i]) 
        {
            printf("Posicao [%d] - Valor [%d]\n", i, vetor[i]);
        }
    }

    free(vetor); // desalocacao

    system("pause");
    return 0;
}