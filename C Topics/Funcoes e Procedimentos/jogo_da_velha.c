/*
    JOGO DA VELHA POR FUNCOES E PROCEDIMETOS
*/

#include <stdio.h>
#include <stdlib.h>

char jogo[3][3];   // matriz de char 3x3 do jogo
int linha, coluna; // indices para linha e colunas da matriz

void inicializar_matriz()
{
    for (linha = 0; linha < 3; linha++)
    {
        for (coluna = 0; coluna < 3; coluna++)
        {
            jogo[linha][coluna] = ' ';
        }
    }
}

void imprimir_matriz()
{
    printf("\n\n\t 0   1   2\n\n");
    for (linha = 0; linha < 3; linha++)
    {
        for (coluna = 0; coluna < 3; coluna++)
        {
            if (coluna == 0)                     // se for inicio da linha
                printf("\t");                    // imprime uma tabulacao (espaco)
            printf(" %c ", jogo[linha][coluna]); // imprime caractere da matriz na posicao atual
            if (coluna < 2)                      // se nao for a ultima coluna
                printf("|");                     // imprime caractere para dividir colunas
            if (coluna == 2)
                printf("   %d", linha); // imprime o indice da linha a direita
        }
        printf("\n");
        if (linha < 2)                // se nao for a ultima linha
            printf("\t----------\n"); // imprime linha tracejada que divide as linhas
    }
}

/*
    função para verificar vitória do jogador c na linha l
    1 - ganhou
    0 - não ganhou ainda
    char c - caractere que identifica 0 ou X
*/
int ganhouPorLinha(int l, char c)
{
    if (jogo[l][0] == c && jogo[l][1] == c && jogo[l][2] == c)
        return 1;
    else
        return 0;
}

/*
    função para verificar vitória do jogador c nas linhas
    1 - ganhou
    0 - não ganhou ainda
*/
int ganhouPorLinhas(char c)
{
    int ganhou = 0;
    for (linha = 0; linha < 3; linha++)
    {
        ganhou += ganhouPorLinha(linha, c);
    }
    return ganhou;
}

/*
    função para verificar vitória do jogador j na coluna c
    1 - ganhou
    0 - não ganhou ainda
*/
int ganhouPorColuna(int c, char j)
{
    if (jogo[0][c] == j && jogo[1][c] == j && jogo[2][c] == j)
        return 1;
    else
        return 0;
}

/*
    função que verifica vitória do jogador j por colunas
    1 - ganhou
    0 - não ganhou ainda
*/
int ganhouPorColunas(char j)
{
    int ganhou = 0;
    for (coluna = 0; coluna < 3; coluna++)
    {
        ganhou += ganhouPorColuna(coluna, j);
    }
    return ganhou;
}

/*
    função para verificar vitória do jogador c na diagonal principal
    1 - vitória
    0 - não ganhou
*/
int ganhouPorDiagPrin(char c)
{
    if (jogo[0][0] == c && jogo[1][1] == c && jogo[2][2] == c)
        return 1;
    else
        return 0;
}

/*
    função para verificar vitória do jogador c na diagonal secundária
    1 - vitória
    0 - não ganhou
*/
int ganhouPorDiagSec(char c)
{
    if (jogo[0][2] == c && jogo[1][1] == c && jogo[2][0] == c)
        return 1;
    else
        return 0;
}

/*
    função que diz se uma coordenada é válida ou não
    1 - é válida
    0 - não é válida
*/
int ehValida(int l, int c)
{
    if (l >= 0 && l < 3 && c >= 0 && c < 3 && jogo[l][c] == ' ')
        return 1;
    else
        return 0;
}

// procedimento para ler as coordenadas digitadas pelo jogador
void lerCoordenadas(char j)
{
    int l, c;

    printf("Digite linha e coluna: ");
    scanf("%d%d", &l, &c);

    while (ehValida(l, c) == 0)
    {
        printf("Coordenadas invalidas! Digite outra linha e coluna: ");
        scanf("%d%d", &l, &c);
    }
    jogo[l][c] = j;
}

// função que retorna a quantidade de posições ainda vazias (não jogadas)
int quantVazias()
{
    int quantidade = 0;

    for (linha = 0; linha < 3; linha++)
    {
        for (coluna = 0; coluna < 3; coluna++)
            if (jogo[linha][coluna] == ' ')
                quantidade++;
    }
    return quantidade;
}

// procedimento jogar com o loop (repetição) principal do jogo
void jogar()
{
    int jogador = 1, vitoriaX = 0, vitoria0 = 0;
    char jogador1 = 'X', jogador2 = '0';

    do
    {
        imprimir_matriz();
        if (jogador == 1)
        {
            lerCoordenadas(jogador1);
            jogador++;
            vitoriaX += ganhouPorLinhas(jogador1);
            vitoriaX += ganhouPorColunas(jogador1);
            vitoriaX += ganhouPorDiagPrin(jogador1);
            vitoriaX += ganhouPorDiagSec(jogador1);
        }
        else
        {
            lerCoordenadas(jogador2);
            jogador = 1;
            vitoria0 += ganhouPorLinhas(jogador2);
            vitoria0 += ganhouPorColunas(jogador2);
            vitoria0 += ganhouPorDiagPrin(jogador2);
            vitoria0 += ganhouPorDiagSec(jogador2);
        }
    } while (vitoriaX == 0 && vitoria0 == 0 && quantVazias() > 0);

    imprimir_matriz();

    if (vitoria0 == 1)
        printf("\nParabens Jogador 2. Voce venceu!!!\n");
    else if (vitoriaX == 1)
        printf("\nParabens Jogador 1. Voce venceu!!!\n");
    else
        printf("\nQue pena. Perderam!!!\n");
}

int main()
{
    int opcao;

    do
    {
        inicializar_matriz();
        jogar();

        printf("\nDigite 1 para jogar novamente: ");
        scanf("%d", &opcao);
    } while (opcao == 1);

    system("pause");
    return 0;
}