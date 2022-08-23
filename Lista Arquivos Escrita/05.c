/*
5. Faça um programa que receba N informações sobre alunos contendo
Nome, Nota1, Nota2, calcule a média e considerando como critério para
aprovação Média 70 apresente o resultado “Aprovado” ou “Reprovado”.
Todas as informações devem ser gravadas em um arquivo de formato
“a”.
*/

#include <stdio.h>
#include <string.h>
struct alunos // informacoes dos alunos
{
    char nome[31];
    int nota1, nota2, nota3, media;
} cad[10];

int main()
{
    FILE *arquivo;
    arquivo = fopen("aprovacoes.txt", "a"); // abrindo arquivo para escrita
    if (arquivo == NULL)                    // testando abertura do arquivo
    {
        printf("Erro na abertura do arquivo.\n");
    }
    for (int i = 0; i < 1; i++) // leitura de dados
    {
        printf("Nome do aluno: ");
        fgets(cad[i].nome, 31, stdin);
        fflush(stdin);
        printf("Informe as 3 notas [0 - 10]: ");
        scanf("%d%d%d", &cad[i].nota1, &cad[i].nota2, &cad[i].nota3);
        fflush(stdin);
        printf("\n");
        cad[i].media = (cad[i].nota1 + cad[i].nota2 + cad[i].nota3) / 3; // calculo de media

        fprintf(arquivo, "Nome: %s", cad[i].nome); // escrita dos dados no arquivo
        fprintf(arquivo, "Nota 1: %d | Nota 2: %d | Nota 3: %d\n", cad[i].nota1, cad[i].nota2, cad[i].nota3);
        fprintf(arquivo, "Media: %d\n", cad[i].media);
        if (cad[i].media >= 70)
        {
            fprintf(arquivo, "APROVADO\n\n");
        }
        else if (cad[i].media < 70)
        {
            fprintf(arquivo, "REPROVADO\n\n");
        }
    }
    fclose(arquivo);
    return 0;
}