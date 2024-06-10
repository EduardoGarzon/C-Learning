/*
    Encontrando o maior e o menor elemento de um vetor com ponteiro.

    Ponteiros resolvem o problema de uma funcao retornar apenas um valor.
    Ao inves de retornar os valores das vars maior e menor,
    passamos como paramentro o endereco dessas vars sem necessidade de retorno.
*/

#include <stdio.h>
#include <stdlib.h>

void maiorMenor(int *maior, int *menor, int *vet, int tam)
{
    // Conteudo dos ponteiros maior e menor recebem o primeiro elemento do vetor.
    *maior = *vet;
    *menor = *vet;

    // Compara a partir do segundo valor ja que o primeiro foi atribuido em maior e menor acima.
    for (int i = 1; i < tam; i++)
    {
        if (*menor > *(vet + i))
        {
            *menor = *(vet + i);
        }
        if (*maior < *(vet + i))
        {
            *maior = *(vet + i);
        }
    }
}

int main()
{
    int maior = 0, menor = 0, vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // & em maior e menor por nao serem ponteiro por isso passamos o enderecos dele.
    // vet nao recebe & por ja se tratar de um ponteiro.
    maiorMenor(&maior, &menor, vet, 10);

    printf("Maior valor: %d | Menor Valor: %d\n", maior, menor);

    system("pause");
    return 0;
}