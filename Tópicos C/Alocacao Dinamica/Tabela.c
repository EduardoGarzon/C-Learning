/**
 * @file Tabela.c
 * @author Luiz Eduardo
 * @brief Exemplo de Tabela em C
 * @version 0.1
 * @date 2023-07-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(const int argv, const char *argc[])
{
    // tamanhos da linha e coluna da tabela
    int linha = atoi(argc[1]);
    int coluna = atoi(argc[2]);

    // Alocacao da tabela de chars para os nomes
    char **tabela;
    tabela = calloc(linha, sizeof(char *)); // aloca linhas da tabela, vetor de ponteiros para char
    for (int i = 0; i < linha; i++)
    {
        tabela[i] = calloc(coluna, sizeof(char *)); // aloca colunas da tabela, vetor de char
    }

    // Leitura dos nomes na tabela
    for (int i = 0; i < linha; i++)
    {
        printf("Informe o nome da linha [%d] da tabela: ", i);
        scanf("%s", tabela[i]);
        fflush(stdin);
    }

    // Impressao da tabela
    printf("\n\n     TABELA DE NOMES\n");
    for (int i = 0; i < linha; i++)
    {
        printf("%d.[", i);
        for (int j = 0; j < coluna; j++)
        {
            printf("%c ", tabela[i][j]);
        }

        int espacos = coluna - strlen(tabela[i]) - 1;
        for (int j = 0; j < espacos; j++)
        {
            printf(" ");
        }
        printf("]\n");
    }

    // Liberar memória alocada
    for (int i = 0; i < linha; i++)
    {
        free(tabela[i]);
    }
    free(tabela);

    return 0;
}