/*
6. Escreva um programa que leia primeiro os 6 números gerados pela loteria e depois os 6
números do seu bilhete. O programa então compara quantos números o jogador acertou. Em
seguida, ele aloca espaço para um vetor de tamanho igual a quantidade de números corretos e
guarda os números corretos nesse vetor. Finalmente, o programa exibe os números sorteados
e os seus números corretos.
*/

#include <stdio.h>
#include <stdlib.h> // funcao malloc() e srand()
#include <time.h>   // funcao time()

int main()
{
    int loteria[6] = {0, 0, 0, 0, 0, 0}; // valores da loteria
    int bilhete[6] = {0, 0, 0, 0, 0, 0}; // valores da aposta
    int i = 0, j = 0, x = 0;             // indices dos lacos de repeticao
    int sort = 0;                        // variavel que recebe o numero aleatorio da loteria
    int flag = 0;                        // flag para testes de erro
    int numero = 0;                      // variavel que recebe o numero a ser apostado
    int pontos = 0;                      // variavel que contem o total de numero de acertos
    int *sorteio;                        // ponteiro para a alocao do vetor dos numeros acertados

    srand(time(NULL));
    while (i < 6) // sorteia numeros aleatorios para a loteria
    {
        sort = 1 + (rand()) % 10;
        for (int j = 0; j < 6; j++)
        {
            if (sort == loteria[j] || sort == 0) // erro se numero == 0 ou ja existir na loteria
            {
                flag = 1; // flag de erro recebe 1
            }
        }
        if (flag == 0) // numero valido se flag == 0
        {
            loteria[i] = sort;
            i++;
        }
        flag = 0;
    }
    i = 0;
    flag = 0;
    printf("Informe os valores que deseja apostar: \n");
    while (i < 6) // lendo os numeros apostados
    {
        printf("Informe o %d valor para apostar: ", i + 1);
        scanf("%d", &numero);
        for (j = 0; j < 6; j++)
        {
            if (numero == bilhete[j] || numero == 0) // verifica so o numero == 0 ou se ja foi apostado
            {
                flag = 1; // flag de erro = 1 se sim
            }
        }
        if (flag == 0) // flag de erro == 0 valida o numero
        {
            bilhete[i] = numero;
            i++;
            for (x = 0; x < 6; x++) // verifica se o numero apostado é igual o sorteado
            {
                if (numero == loteria[x])
                {
                    pontos++; // incrementas pontos se o numero for igual ao sorteio
                }
            }
        }
        flag = 0; // zera flag para proximos testes
    }

    sorteio = calloc(pontos, sizeof(int)); // aloca conforme a quantidade de acertos
    x = 0;
    for (i = 0; i < 6; i++) // verifica os numeros acertados
    {
        for (j = 0; j < 6; j++)
        {
            if (bilhete[i] == loteria[j]) // compara se o valor do bilhete é igual o da loteria
            {
                sorteio[x] = bilhete[i]; // espaco alocado recebe o numero acertado
                x++;
            }
        }
    }
    printf("\n");
    printf("Loteria: \n"); // imprime os numeros da loteria
    for (i = 0; i < 6; i++)
    {
        printf("[%d] ", loteria[i]);
    }
    printf("\n\n");
    printf("Numeros Acertados: \n"); // imprime os numeros acertados
    for (i = 0; i < pontos; i++)
    {
        printf("[%d] ", sorteio[i]);
    }
    printf("\nPontuacao: %d", pontos); // imprime a pontuacao
    free(sorteio);
    return 0;
}