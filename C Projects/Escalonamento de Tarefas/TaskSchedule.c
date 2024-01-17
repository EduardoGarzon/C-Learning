/*
    Cenário: Você é responsável por gerir a distribuição das salas de aula
    de uma instituição de ensino para o ano letivo.
    Como os recursos são finitos, cada sala usada
    deve ser aproveitadada melhor forma possível

        Aula       Inicio      Fim
        Artes      - 9:00 am   - 10:00 am
        Ingles     - 9:30 am   - 10:30 am
        Matematica - 10:00 am  - 11:00 am
        CC         - 10:30 am  - 11:30 am
        Música     - 11:00 am  - 12:00 pm
*/

#include <stdio.h>
#include <stdlib.h>

int tamanho = 0;

typedef struct CronogramaSala
{
    char nome[4];
    int inicio;
    int fim;
    int disp;
    int sala;
} aulas;

typedef struct SaladeAula
{
    int disp_sala;
    int id_sala;
} salas;

aulas *point;
salas *point2;
salas *point3;

void taskschedule()
{
    int fimaula = -1;
    int menor = 99999;
    int aula_atual = 0;
    int i = 0;
    int voltas = 0;

    int qtd_salas = 1;

    point2 = malloc(qtd_salas * sizeof(salas));

    while (voltas < tamanho)
    {
        for (i = 0; i < tamanho; i++) // seleciona a aula que comeca mais cedo
        {
            if (point[i].disp == 0)
            {
                if (point[i].inicio < menor)
                {
                    aula_atual = i;
                    menor = point[i].inicio;
                }
            }
        }

        menor = 9999;

        if (point[aula_atual].inicio >= fimaula)
        {
            fimaula = point[aula_atual].fim;
            point[aula_atual].disp = 1;
        }
        else
        {
            point[aula_atual].disp = -1;
        }

        if (point2[qtd_salas].disp_sala != 1)
        {
            point2[qtd_salas].disp_sala = 1;
            point2[qtd_salas].id_sala = qtd_salas;
            point[aula_atual].sala = point2[qtd_salas].id_sala;
        }
        else
        {
            point3 = realloc(point2, qtd_salas++ * sizeof(salas));
            point3->disp_sala = 1;
            point2[qtd_salas].id_sala = qtd_salas++;
            point[aula_atual].sala = point2[qtd_salas].id_sala;
        }

        printf("Aula: %s\n", point[aula_atual].nome);
        printf("Sala: %d\n", point[aula_atual].sala);
        printf("\n");

        voltas++;
    }

    printf("Quantidade de Salas Utilizadas: %d\n", qtd_salas);
}

int main()
{

    printf("Infome a quantidade de materias: ");
    scanf("%d", &tamanho);

    point = malloc(tamanho * sizeof(aulas));

    int cont = 0;

    do
    {
        printf("Nome da Materia: ");
        scanf("%s", point[cont].nome);

        printf("Inicio: ");
        scanf("%d", &point[cont].inicio);

        printf("Fim: ");
        scanf("%d", &point[cont].fim);

        point[cont].disp = 0;

        printf("\n");

        cont++;
    } while (cont < tamanho);

    taskschedule();
    free(point);

    system("pause");
    return 0;
}
