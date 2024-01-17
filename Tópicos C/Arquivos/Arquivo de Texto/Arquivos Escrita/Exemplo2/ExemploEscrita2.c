/*
    O IBOP realizou uma pesquisa a nível nacional.
    Foi entrevistado um certo número de pessoas.
    Cada pessoa respondeu ao seguinte questionário:
        Sexo: ( )M ( )F
        Idade: ____ anos
        Fumante: ( )S ( )N

    Considere um arquivo de texto de registros (denominado “ibop.txt”) que
    contém as respostas de todas as pessoas entrevistadas. Cada registro
    armazena a resposta de uma pessoa entrevistada através dos seguintes
    campos: sexo (um caractere, podendo ser ‘M’ ou ‘F’), idade (valor
    inteiro), fumante (um caractere, podendo ser ‘S’ ou ‘N’).
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int resposta = 1, idade;
    char sexo, fumante;

    FILE *arquivo;
    arquivo = fopen("ibop.txt", "w"); // abertura de arquivo para escrita
    if (arquivo == NULL)              // teste de abertura do arquivo
    {
        printf("\n");
        printf("Erro na abertura de arquivo.\n");
    }

    while (resposta == 1) // leitura de dados
    {
        printf("\n");
        printf("Sexo [M | F]: ");
        scanf(" %c", &sexo);

        printf("Idade: ");
        scanf("%d", &idade);

        printf("Fumante [S | N]: ");
        scanf(" %c", &fumante);

        fprintf(arquivo, "Sexo [M | F]: %c\n", sexo); // escrevendo dados no arquivo
        fprintf(arquivo, "Idade: %d\n", idade);
        fprintf(arquivo, "Fumante [S | N]: %c\n\n", fumante);

        printf("Continuar? [0 | 1]: ");
        scanf("%d", &resposta);
    }

    fclose(arquivo);

    system("pause");
    return 0;
}