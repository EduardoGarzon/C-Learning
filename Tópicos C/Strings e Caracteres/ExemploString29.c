/*
    Faça um subprograma que leia um texto de até 80 caracteres e
    devolva, em um vetor, a distribuição de frequência
    de comprimento de palavras do texto.

    Considerar que, no texto, podem aparecer palavras de até 10 caracteres e
    que a menor palavra tem apenas dois caracteres.

    As palavras podem estar separadas por espaços em branco ou
    pelos caracteres vírgula ou ponto.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 80

int main()
{
    char texto[size];   // string para o texto
    int vetor[40];      // armazena o comprimento de cada palavra
    int frequencia[20]; // armazenar as frequencias do comprimento de cada palavra

    int flag = 0;            // flag de operaco
    int x = 0, i = 0, j = 0; // indices
    int aux;                 // auxiliar para troca de posicoes na ordencao do vetor

    printf("Digite seu texto: "); // entrada de caracteres para o vetor texto
    fgets(texto, size, stdin);

    for (i = 0; i <= (int)strlen(texto); i++) // varrendo todos o caracteres
    {
        // testes que desconsideram os caracteres especiais, space-bar e enter
        if (texto[i] != ' ' && texto[i] != '.' && texto[i] != ',' && texto[i + 1] != '\0')
        {
            flag++; // soma flag para representar o comprimento de cada palavra
        }
        else
        {
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
    // inicia em 1 pois o primeiro elemento ja esta presente para as comparacoes adiantes.
    flag = 1;

    for (i = 0; i < x; i++) // fazendo a distribuicao de frequencia simples
    {
        if (vetor[i] == vetor[i + 1])
        {
            // calculando quantas vezes cada elemento repetiu, faz a frequencia simples
            flag++;
        }
        else
        {
            frequencia[j] = flag; // adicionando as frequencias no vetor frequencia
            j++;
            flag = 1;
        }
    }

    printf("Vetor ordenado contendo os comprimentos de cada palavra: ");
    for (i = 0; i < x; i++) // Vetor ordenado, rol dos comprimentos de cada palavra
    {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    printf("Vetor contendo a frequencia de cada comprimento de palavra: ");
    // vetor contendo a frequencia de cada comprimento de palavra do rol
    for (i = 0; i < j; i++) 
    {
        printf("%d ", frequencia[i]);
    }

    printf("\n");

    system("pause");
    return 0;
}