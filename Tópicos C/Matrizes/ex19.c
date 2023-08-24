/* 19. Desenvolva um algoritmo que simule o jogo da velha.
Ele deve permitir movimentos alternados de dois jogadores;
verificar se uma jogada é válida ou não;
verificar ao término do jogo, qual jogador ganhou ou se houve empate. */

#include <stdio.h>

int main()
{
    int matriz[3][3];         // matriz jogo da velha
    int i, j, x, y;           // indice da posicao dos jogadores A e B
    int cont;                 // indice das rodadas
    int flag = 0;             // flag de detecao da posicao
    int flagA = 0, flagB = 0; // flag de teste de resposta das jogadas

    printf("| JOGO DA VELHA 3x3|\n");
    printf("|------------------|\n");
    printf("| 1 para Jogador A |\n");
    printf("| 2 para Jogador B |\n");
    printf("|------------------|\n");

    for (i = 0; i < 3; i++) // escrevendo a matriz atribuida em 0
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            matriz[i][j] = 0;
            printf("%d ", matriz[i][j]);
        }
    }

    for (cont = 0; cont < 5; cont++) // 2 atribuicoes totalizam 5 rodadas para completar a matriz
    {

        flagA = 0;
        flagB = 0;
        for (i = 0; i < 3; i++) // testando jogadas nas linhas
        {
            for (j = 0; j < 3; j++)
            {
                if (matriz[i][j] == 1)
                {
                    flagA++; // linha A
                }
                else if (matriz[i][j] == 2)
                {
                    flagB++; // linha B
                }
            }
            if (flagA == 3)
            {
                break;
            }
            else if (flagB == 3)
            {
                break;
            }
            else
            {
                flagA = 0;
                flagB = 0;
            }
        }

        if (flagA == 3) // resultados
        {
            printf("\nJOGADOR A VENCEDOR.");
            break;
        }
        else if (flagB == 3)
        {
            printf("\nJOGADOR B VENCEDOR.");
            break;
        }

        for (i = 0; i < 3; i++) // testando jogadas nas colunas
        {
            for (j = 0; j < 3; j++)
            {
                if (matriz[j][i] == 1)
                {
                    flagA++; // coluna A
                }
                else if (matriz[j][i] == 2)
                {
                    flagB++; // coluna B
                }
            }
            if (flagA == 3)
            {
                break;
            }
            else if (flagB == 3)
            {
                break;
            }
            else
            {
                flagA = 0;
                flagB = 0;
            }
        }

        if (flagA == 3) // resultados
        {
            printf("\nJOGADOR A VENCEDOR.");
            break;
        }
        else if (flagB == 3)
        {
            printf("\nJOGADOR B VENCEDOR.");
            break;
        }

        for (i = 0; i < 3; i++) // testanto jogadas na diagonal principal
        {
            for (j = 0; j < 3; j++)
            {
                if (i == j && matriz[i][j] == 1)
                {
                    flagA++; // diagonal principal A
                }
                else if (i == j && matriz[i][j] == 2)
                {
                    flagB++; // diagonal principal B
                }
            }
        }

        if (flagA == 3) // resultados
        {
            printf("\nJOGADOR A VENCEDOR.");
            break;
        }
        else if (flagB == 3)
        {
            printf("\nJOGADOR B VENCEDOR.");
            break;
        }

        flagA = 0;
        flagB = 0;
        for (i = 0; i < 3; i++) // Testando jogadas na diagonal secundaria
        {
            for (j = 0; j < 3; j++)
            {
                if (i + j == 2 && matriz[i][j] == 1)
                {
                    flagA++; // diagonal secundaria A
                }
                else if (i + j == 2 && matriz[i][j] == 2)
                {
                    flagB++; // diagonal secundaria B
                }
            }
        }

        if (flagA == 3) // resultados
        {
            printf("\nJOGADOR A VENCEDOR.");
            break;
        }
        else if (flagB == 3)
        {
            printf("\nJOGADOR B VENCEDOR.");
            break;
        }

        while (flag == 0) // repete enquanto nao informar uma posicao valida
        {

            printf("\n\nJogador A, informe a posicao i e j: "); // lendo jogador A
            scanf("%d%d", &i, &j);
            if (matriz[i][j] > 0) // testando se a posicao informada ja foi atribuida
            {
                printf("\nPosicao ja utilizada. Informe outro valor.\n");
            }
            else
            {
                matriz[i][j] = 1; // atribuindo A
                flag = 1;
            }
        }

        if (cont < 4)
        {
            while (flag == 1) // repete enquanto nao informar uma posicao valida
            {
                printf("Jogador B, informe a posicao i e j: "); // lendo jogador B
                scanf("%d%d", &x, &y);
                if (matriz[x][y] > 0) // teste se a posicao informada ja foi atribuida
                {
                    printf("\nPosicao ja utilizada. Informe outro valor.\n");
                }
                else
                {
                    matriz[x][y] = 2; // atribuindo o valor de B na posicao informada
                    flag = 0;
                }
            }
        }
        else
        {
            printf("\nEMPATE.\n");
        }

        for (i = 0; i < 3; i++) // escrevendo a nova matriz atribuida
        {
            printf("\n");
            for (j = 0; j < 3; j++)
            {
                printf("%d ", matriz[i][j]);
            }
        }
    }

    return 0;
}