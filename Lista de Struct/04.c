/*
4. Crie uma estrutura representando os alunos de um determinado curso. A estrutura
deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda
prova e nota da terceira prova.
(a) Permita ao usuário entrar com os dados de 5 alunos.
(b) Encontre o aluno com maior nota da primeira prova.
(c) Encontre o aluno com maior média geral.
(d) Encontre o aluno com menor média geral
(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6
para aprovação.
*/

#include <stdio.h>

int main()
{
    int i = 0, x = 0;           // indices e flag de erro na digitacao da nota
    double medias[5], notas[3]; // vetor que armazena a media das notas de cada aluno na ordem

    struct curso // estrutura curso que contem os dados sobre os alunos
    {
        char nome[100];
        double nota[3];
        double soma;
        double media;
    } aluno[5];

    for (x = 0; x < 5; x++) // leitura dos dados
    {
        printf("Informe o nome do aluno: "); // nome do aluno
        fgets(aluno[x].nome, 100, stdin);
        fflush(stdin);
        if (aluno[x].nome[strlen(aluno[x].nome) - 1] == '\n') // substituindo o caractere enter por espaco
        {
            aluno[x].nome[strlen(aluno[x].nome) - 1] = ' ';
        }

        for (i = 0; i < 3; i++)
        {
            printf("Informe a nota %d: ", i + 1);
            scanf("%lf", &aluno[x].nota[i]);
            fflush(stdin);
            aluno[x].soma += aluno[x].nota[i]; // soma das notas informadas
        }
        notas[x] = aluno[x].nota[0];
        aluno[x].media = aluno[x].soma / 3; // media das notas informadas
        medias[x] = aluno[x].media;         // as medias sao armazenadas no vetor medias
        printf("\n");
    }

    int flagmaior = 2, flagmenor = 1, flagnota1 = 0; // flags que indicam os alunos de acordo com a nota
    double maior = medias[2];                        // armazena o segundo valor das medias
    double menor = medias[1];                        // armazena o terceiro valor das medias
    double maior_nota1 = 0;                          // variavel para comparar a maior primeira nota
    for (i = 0; i < 5; i++)                          // comparando as medias com as armazenadas acima
    {
        if (medias[i] > maior) // comparando a primeira com as duas seguites e a segunda com a terceira ja podemos obter quem é a menor e quem é a maior nota
        {
            maior = medias[i];
            flagmaior = i;
        }
        if (medias[i] < menor)
        {
            menor = medias[i];
            flagmenor = i;
        }
        if (notas[i] > maior_nota1) // comparando as primeiras notas para saber qual a maior
        {
            maior_nota1 = notas[i];
            flagnota1 = i;
        }
    }

    for (i = 0; i < 5; i++) // teste para saber se o aluno esta aprovado ou reprovado
    {
        printf("\n");
        printf("Aluno: %s\n", aluno[i].nome);
        printf("Media: %0.1f\n", aluno[i].media);
        if (aluno[i].media >= 60) // media abaixo de 6 configura reprovado
        {
            printf("Situacao: Aprovado");
        }
        else
        {
            printf("Situacao: Reprovado");
        }
        printf("\n");
    }

    printf("\nAluno com a maior nota da primeira prova: %s | Nota: %0.1f\n", aluno[flagnota1].nome, maior_nota1);
    printf("Aluno com a maior media geral: %s | Media: %0.1f\n", aluno[flagmaior].nome, maior);
    printf("Aluno com a menor media geral: %s | Media: %0.1f\n", aluno[flagmenor].nome, menor);
    return 0;
}