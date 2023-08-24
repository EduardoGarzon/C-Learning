/* 10. Faça um subprograma que leia um texto de até 80 caracteres e devolva, em um vetor, a
distribuição de frequência de comprimento de palavras do texto. Considerar que, no
texto, podem aparecer palavras de até 10 caracteres e que a menor palavra tem apenas
dois caracteres. As palavras podem estar separadas por espaços em branco ou pelos
caracteres vírgula ou ponto. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 80

int main()
{
    char texto[size];   // vetor string para o texto
    int vetor[40];      // vetor que armazena o comprimento de cada palavra
    int frequencia[20]; // vetor para armazenar as frequencias do comprimento de cada palavra

    int flag = 0;            // flag de operaco
    int x = 0, i = 0, j = 0; // indices
    int aux;                 // variavel auxiliar para troca de posicoes na ordencao do vetor

    printf("Digite seu texto: "); // entrada de caracteres para o vetor texto
    fgets(texto, size, stdin);

    for (i = 0; i <= strlen(texto); i++) // varrendo todos o caracteres
    {

        if (texto[i] != ' ' && texto[i] != '.' && texto[i] != ',' && texto[i + 1] != '\0')
        // testes que desconsideram os caracteres especiais, space-bar e enter
        {
            flag++; // soma flag para representar o comprimento de cada palavra
            // putchar(texto[i]); // escreve somente se for diferente dos caracteres definidos no if
        }
        else
        {
            // printf(" sinal "); // indica a presenca dos caracteres especiais

            if (flag >= 2 && flag <= 10) // adiciona o comprimento das palavras no vetor
            {
                vetor[x] = flag; // adiciona somente comprimentos de 2 ate 10
                x++;             // indice do vetor
            }
            flag = 0; // zera a flag para calcular o comprimento de outra palavra
        }
    }

    for (i = 0; i < x; i++) // Ordenando o vetor em ordem crescente
    {
        for (j = 0; j < x; j++)
        {
            if (vetor[i] < vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    j = 0;
    flag = 1; // flag inicia em 1 pois o primeiro elemento ja esta presente para as comparacoes adiantes
    for (i = 0; i < x; i++) // fazendo a distribuicao de frequencia simples
    {
        if (vetor[i] == vetor[i + 1])
        {
            flag++; // calculando quantas vezes cada elemento repetiu, faz a frequencia simples
        }
        else
        {
            frequencia[j] = flag; // adicionando as frequencias no vetor frequencia
            j++;
            flag = 1;
        }
    }

    printf("\nVetor ordenado contendo os comprimentos de cada palavra: \n");
    for (i = 0; i < x; i++) // Vetor ordenado, rol dos comprimentos de cada palavra
    {
        printf("%d ", vetor[i]);
    }

    printf("\nVetor contendo a frequencia de cada comprimento de palavra: \n");
    for (i = 0; i < j; i++) // vetor contendo a frequencia de cada comprimento de palavra do rol
    {
        printf("%d ", frequencia[i]);
    }

    return 0;
}