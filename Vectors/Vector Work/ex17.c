/* 17. Ler um vetor B de 9 elementos (reserve espaço para 10 elementos). 
Ler um valor P que representa uma posição dentro do vetor (validar o valor P 
aceitando apenas valores entre 1 a 9). Ler um valor X e colocá-lo na posição P do vetor B 
fazendo com que os elementos existentes dentro do vetor (da posição P em diante) sejam deslocados 
de uma posição para o final. Logo após o processamento escrever o vetor B.
Exemplo: B= 1 2 8 4 3 2 7 5 9;  P=5;  X=15;  B final= 1 2 8 4 15 3 2 7 5 9 */

#include <stdio.h>

int main()
{
    int vetorB[10];
    int posicao = 0;
    int numero = 0;

    for (int i = 0; i < 9; i++)
    {
        printf("Informe um valor: ");
        scanf("%i", &vetorB[i]);
    }

    printf("\nVetor inicial: \n");
    for (int i = 0; i < 9; i++)
    {
        printf("%i\n", vetorB[i]);
    }

    printf("Informe uma posicao de 1 a 9: ");
    scanf("%i", &posicao);

    printf("Informe um valor para a posicao: ");
    scanf("%i", &numero);

    for (int i = 10; i > posicao; i--)
    {
        vetorB[i] = vetorB[i-1];
    }
    vetorB[posicao] = numero;
    

    printf("\nVetor final:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%i\n", vetorB[i]);
    }

    return 0;
}