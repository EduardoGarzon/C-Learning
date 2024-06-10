/*
    Faça um programa que realize a leitura dos seguintes dados
    relativos a um conjunto de alunos: Matricula, Nome, Código da Disciplina, Nota1 e Nota2.

    Considere uma turma de até 10 alunos. Após ler todos os dados digitados,
    e depois de armazenálos em um vetor de estrutura,
    exibir na tela a listagem final dos alunos com as suas respectivas médias finais
    (use uma média ponderada: Nota1 com peso=1.0 e Nota2 com peso=2.0).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nota1 = 0, nota2 = 0; // variaveis de uso global para as notas e media
float media = 0;

float ponderada(int nota1, int nota2, float media) // funcao que calcula a media ponderada
{
    media = ((nota1 * 1) + (nota2 * 2)) / 3;
    return media;
}

int main()
{
    struct cadastro // estrutura que contem as variveis que possuem os dados solicitados
    {
        int matricula;
        char nome[100];
        int codigo;
        float media_final;
    } alunos[10];

    for (int i = 0; i < 10; i++) // leitura dos dados
    {

        printf("Informe a matricula do aluno: ");
        scanf("%d", &alunos[i].matricula);
        fflush(stdin);

        printf("Informe o nome do aluno: ");
        fgets(alunos[i].nome, 100, stdin);
        fflush(stdin);

        // apagando o enter que o fgets coloca, evitando assim de pular linha
        if (alunos[i].nome[strlen(alunos[i].nome) - 1] == '\n')
        {
            alunos[i].nome[strlen(alunos[i].nome) - 1] = ' ';
        }

        printf("Informe o codigo da disciplina: ");
        scanf("%d", &alunos[i].codigo);
        fflush(stdin);

        printf("Informe a primeira e segunda nota do aluno: ");
        scanf("%d%d", &nota1, &nota2);
        fflush(stdin);

        printf("\n");

        // chamada da funcao que vai calcular a media ponderada
        alunos[i].media_final = ponderada(nota1, nota2, media);
    }

    for (int i = 0; i < 10; i++) // escrevendo os dados informados para a estrutura
    {
        printf("\n\n");
        printf("Matricula: %d | Nome: %s \n", alunos[i].matricula, alunos[i].nome);
        printf("Codigo da disciplina: %d\n", alunos[i].codigo);
        printf("Media Ponderada das notas informadas: %0.2f", alunos[i].media_final);
    }

    system("pause");
    return 0;
}