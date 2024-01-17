/*
    Construa uma estrutura aluno com nome, número de matrícula e curso.
    Leia do usuário a informação de 5 alunos,
    armazene em vetor dessa estrutura e imprima os dados na tela.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct cadastro // nome da estrutura
    {
        char nome[50]; // variavel e vetor da estrutura
        int matricula;
        char curso[50];

    } aluno[5]; // nome da vetor do tipo struct

    int i = 0; // indice dos for

    printf("Cadastre 5 alunos\n");

    for (i = 0; i < 5; i++) // leitura da variavel e vetores da estrutura
    {
        printf("Nome do aluno: ");
        gets(aluno[i].nome);
        // fgets(aluno[i].nome, 50, stdin);
        fflush(stdin);

        printf("Numero da matricula: ");
        scanf("%d", &aluno[i].matricula);
        fflush(stdin);

        printf("Nome do curso: ");
        fgets(aluno[i].curso, 50, stdin);
        // gets(aluno[i].curso);
        fflush(stdin);

        printf("\n");
    }

    // escrevendo os dados armazenados na variavel e vetor da estrutura
    printf("Alunos matriculados: \n");
    for (i = 0; i < 5; i++)
    {
        printf("Nome: %s | Matricula: %d | Curso: %s", aluno[i].nome, aluno[i].matricula, aluno[i].curso);
    }

    system("pause");
    return 0;
}