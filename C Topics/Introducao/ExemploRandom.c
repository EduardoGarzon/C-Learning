#include <stdio.h>
#include <stdlib.h> // para funcao rand e srand
#include <time.h>   // para funcao time

int main()
{
    // --------------------------------------------------------------------- EXEMPLO 1

    // Para gerar um número aleatório (randômico) utilizamos a função
    // que rand pertencente à biblioteca stdlib.h.

    // Quando esta função é chamada ela produz um valor aleatório
    // na faixa entre 0 e a constante RAND_MAX.

    // Para a função rand funcionar ela precisa de um valor inicial chamado de “semente”.
    // Se nenhum valor é passado rand assume um valor constante.
    // No caso a função assume 1.
    // Como este valor, ou seja 1, é assumido sempre,
    // a sequência gerada será a mesma para cada execução.

    printf("Gerando 10 numero aleatorios entre 0 e 100 com a mesma semente.\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", rand() % 100); // gerando 10 numeros aleatorios entre 0 e 100
    }

    // --------------------------------------------------------------------- EXEMPLO 2

    // Para fazer com que os valores gerados não se repitam precisamos usar a função srand
    // a fim de inicializar a função rand com um valor “semente”
    // para que se produza um valor aleatório na faixa determinada.

    // srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
    // com o valor da função time(NULL). Este por sua vez, é calculado
    // como sendo o total de segundos passados desde 1 de janeiro de 1970
    // até a data atual.
    // Desta forma, a cada execução o valor da "semente" será diferente.

    printf("\n\n");
    printf("Gerando 10 numero aleatorios entre 0 e 100 com semente diferente.\n");
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", rand() % 100);
    }

    // --------------------------------------------------------------------- EXEMPLO 3

    int min, max;
    printf("\n\n");
    printf("Gerando 10 numeros aleatorios na faixa informada pelo usuario.\n");

    printf("Informe uma faixa de numero minimo: ");
    scanf("%d", &min);

    printf("Informe uma faixa de numero maximo: ");
    scanf("%d", &max);

    for (int i = 0; i < 10; i++)
    {
        int num = min + (rand()) % (max - min);
        printf("%d ", num);
    }

    system("pause");
    return 0;
}