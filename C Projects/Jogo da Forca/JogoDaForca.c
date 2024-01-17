// Exemplo de jogo da forca em C.
// 5 chances cada jogada.
// O jogador deve acertar todas as letras para ganhar.
// Zerando as 5 chances perde, acertando todas as letras vence.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int chances = 5; // chances para as jogadas
int aux = 0;
char palavra[11]; // string para a palavra a ser adivinhada
char x[11];       // string auxiliar
char letra;       // variavel para letra informada

void show(char palavra[], char letra)
{
    int i = 0;

    if (aux <= 0) // letra errada ou palavra informada no inicio do jogo: exibe a palavra
    {
        printf("PALAVRA: %s", x);
        printf("CHANCES: %d\n", chances);
    }
    if (aux > 0) // letra certa: exibe palavra com a letra substituindo os Xs
    {
        for (int i = 0; i < strlen(x); i++)
        {
            if (letra == palavra[i])
            {
                x[i] = letra;
            }
        }

        printf("PALAVRA: %s", x);
        printf("CHANCES: %d\n", chances);
    }

    aux = 0; // zera para proximas jogadas

    if (chances <= 0) // testa chances das jogadas
    {
        printf("\n----------------------------------------\n");
        printf("   VOCE PERDEU O JOGO TENTE NOVAMENTE!      ");
        printf("\n----------------------------------------\n");
    }
    else
    {
        endgame(x, palavra); // funcao que testa a chance de vitoria
    }
}

void endgame(char x[], char palavra[])
{
    int aux2 = 0;

    for (int i = 0; i < strlen(palavra); i++) // compara a string da palavra informada
    {                                         // com a string auxiliar das respostas
        if (x[i] == palavra[i])
        {
            aux2++;
        }
    }

    if (aux2 == strlen(palavra)) // se strings igual, venceu o jogo
    {
        printf("\n--------------------------------\n");
        printf("\n    VOCE ACERTOU A PALAVRA!\n     ");
        printf("\n--------------------------------\n");

        exit(0); // encerra programa
    }

    theplay(letra); // continua jogadas caso nao ocorra vitoria
}

void theplay(char letra) // funcao para tentativas
{
    printf("Informe a letra: ");
    scanf("%c", &letra);
    fflush(stdin);

    letra = tolower(letra); // passa para minuscula

    printf("\n");

    compare(letra, palavra); // dispara funcao que compara a letra com a string da palavra
}

void compare(char letra, char palavra[])
{
    for (int i = 0; i < strlen(palavra); i++) // compara letra com a string
    {
        if (letra == palavra[i])
        {
            aux++; // incrementa se letra estiver presente
        }
    }
    if (aux <= 0)
    {
        chances--; // perde chances se a letra estiver errada
    }

    show(palavra, letra); // dispara funcao que mostra a palavra
}

int main()
{
    // informando a palavra para ser adivinhada
    printf("INFORME A PALAVRA PARA ADIVINHAR: ");
    fgets(palavra, 12, stdin);
    fflush(stdin);

    strlwr(palavra); // string inteira para minuscula

    system("cls"); // apaga o console apos a palavra ser informada

    for (int i = 0; i < strlen(palavra); i++) // preenche string auxiliar com X
    {
        if (palavra[i] == '\n')
        {
            x[i] = '\n';
            break;
        }
        x[i] = 'X';
    }

    show(palavra, letra);

    system("pause");
    return 0;
}