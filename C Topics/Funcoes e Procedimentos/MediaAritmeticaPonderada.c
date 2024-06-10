/*
    Elabore uma função que receba três notas de um aluno como parâmetros e
    uma letra. Se a letra for A, a função deverá calcular a média aritmética das
    notas do aluno; se for P, deverá calcular a média ponderada, com pesos 5,
    3 e 2.
*/

#include <stdio.h>
#include <stdlib.h>

float calculo(nota1, nota2, nota3, opcao)
{
    float media = 0;

    if (opcao == 'A') // calcula a media de acordo com a opcao selecionada
    {
        media = (nota1 + nota2 + nota3) / 3;
    }
    else if (opcao == 'P')
    {
        media = ((nota1 * 5) + (nota2 * 3) + (nota3 * 2)) / (5 + 3 + 2);
    }
    else
    {
        printf("Opcao invalida, tente novamente!\n");
    }

    return media;
}

int main()
{
    int nota1 = 0, nota2 = 0, nota3 = 0; // variaveis para notas
    float media;                         // variavel para media
    char opcao;                          // variavel para selecionar a opcao desejada

    printf("Informe a primeira nota: ");
    scanf("%d", &nota1);
    printf("Informe a segunda nota: ");
    scanf("%d", &nota2);
    printf("Informe a terceira nota: ");
    scanf("%d", &nota3);
    printf("[A]Media aritmetica | [P]Media Ponderada : ");
    scanf(" %c", &opcao);
    printf("\n");

    media = calculo(nota1, nota2, nota3, opcao); // funcao que retorna a media selecionada

    if (opcao == 'A') // teste para informar o resultado da media escolhida
    {
        printf("Media aritmetica das notas informadas: %.2f\n", media);
    }
    if (opcao == 'P')
    {
        printf("Media ponderada das notas informadas: %.2f\n", media);
    }

    system("pause");
    return 0;
}