/*
    Escreva um trecho de código para fazer a criação dos novos tipos de dados
    conforme solicitado abaixo:
        Horário: composto de hora, minutos e segundos.
        Data: composto de dia, mês e ano.
        Compromisso: composto de uma data, horário e texto que descreve o compromisso.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct dados // struct para os dados da agenda
    {
        int hora, minuto, segundo;
        int dia, mes, ano;
        char comp[100];
    } info[5];

    int i = 0, resposta = 0; // indice e variavel para respostas
    int flag_erro = 0;       // variavel para teste de erro

    while (resposta == 0 && i < 5)
    {
        printf("Tarefa atual [%d de 5]\n", i);

        while (flag_erro == 0) // teste de erro para verificar se é valido
        {
            printf("Informe hora, minuto e segundo [03 20 10]: ");
            scanf("%d%d%d", &info[i].hora, &info[i].minuto, &info[i].segundo);
            fflush(stdin);

            if (info[i].hora <= 23 && info[i].minuto <= 59 && info[i].segundo <= 59)
            {
                flag_erro = 1; // recebe 1 se passar no teste dando continuidade no teste
            }
            else
            {
                printf("Argumento invalido, tente novamente!\n"); // repete se nao passar
            }
        }

        while (flag_erro == 1) // teste para verificar se os dados da data sao validos
        {
            printf("Informe a data [31 05 2022]: ");
            scanf("%d %d %d", &info[i].dia, &info[i].mes, &info[i].ano);
            fflush(stdin);

            if (info[i].dia <= 31 && info[i].mes <= 12)
            {
                flag_erro = 0; // recebe 0 se passar no teste
            }
            else
            {
                printf("Argumento invalido, tente novamente!\n"); // repete se der erro
            }
        }

        printf("Informe seu compromisso: [100 caracteres limite]: ");
        fgets(info[i].comp, 100, stdin);
        fflush(stdin);

        i++;

        printf("Cadastrar mais tarefas? [S - 0/N - 1]: ");
        scanf("%d", &resposta); // posibilita controlar quantas tarefas deseja cadastrar

        printf("\n");
    }

    resposta = 0;   // zera resposta para usar no proximo while
    int tarefa = 0; // variavel para escolher qual tarefa acessar
    i -= 1;         // tira um do indice para nao pegar valores aleatorios

    while (resposta == 0)
    {
        printf("Informe qual tarefa deseja acessar [0 - %d]: ", i);
        scanf("%d", &tarefa);

        if (tarefa <= i) // teste para verificar se a opcao selecionada e valida
        {                // escreve a tarefa informada
            printf("Tarefa [%d]\n", tarefa);
            printf("Horario: %dhr.%dmin.%dseg\n", info[tarefa].hora, info[tarefa].minuto, info[tarefa].segundo);
            printf("Data: %d|%d|%d\n", info[tarefa].dia, info[tarefa].mes, info[tarefa].ano);
            printf("Compromisso: %s\n", info[tarefa].comp);

            printf("Acessar mais tarefas? [Sim - 0 | Nao - 1]: ");
            scanf("%d", &resposta);
        }
        else
        {
            printf("Tarefa nao cadastrada!\n"); // erro se selecionar uma tarefa nao cadastrada

            printf("Continuar? [Sim - 0 | Nao - 1]: ");
            scanf("%d", &resposta);
        }
    }

    system("pause");
    return 0;
}