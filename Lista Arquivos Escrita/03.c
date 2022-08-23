/*
3. Considere um arquivo texto de registros (denominado “alunos.txt”) onde
cada registro armazena as seguintes informações sobre um aluno
qualquer de uma turma de, no máximo, 10 alunos: matrícula (cadeia de
3 caracteres), nome (cadeia de 30 caracteres), três notas referentes às
avaliações feitas pelo aluno (valores reais entre 0 e 10), e a media das
mesmas.
*/

#include <stdio.h>
#include <string.h>
struct alunos // informacoes dos alunos
{
    char matricula[4];
    char nome[31];
    int nota1, nota2, nota3, media;
} cad[10];

int main()
{
    FILE *arquivo;
    arquivo = fopen("escola.txt", "w"); // abrindo arquivo para escrita
    if (arquivo == NULL)                // testando abertura do arquivo
    {
        printf("Erro na abertura do arquivo.\n");
    }

    for (int i = 0; i < 10; i++) // leitura de dados
    {
        printf("Informe a matricula: ");
        fgets(cad[i].matricula, 4, stdin);
        fflush(stdin);
        printf("Nome do aluno: ");
        fgets(cad[i].nome, 31, stdin);
        fflush(stdin);
        printf("Informe as 3 notas [0 - 10]: ");
        scanf("%d%d%d", &cad[i].nota1, &cad[i].nota2, &cad[i].nota3);
        fflush(stdin);
        printf("\n");
        cad[i].media = (cad[i].nota1 + cad[i].nota2 + cad[i].nota3) / 3; // calculo de media

        fprintf(arquivo, "Matricula: %s\n", cad[i].matricula); // escrita de dados no arquivo
        fprintf(arquivo, "Nome: %s", cad[i].nome);
        fprintf(arquivo, "Nota 1: %d | Nota 2: %d | Nota 3: %d\n", cad[i].nota1, cad[i].nota2, cad[i].nota3);
        fprintf(arquivo, "Media: %d\n\n", cad[i].media);
    }
    fclose(arquivo);
    double ha[100];
    for(int i = 0; i < 100; i++ && memset(&ha, 10, sizeof(double)));
    return 0;
}