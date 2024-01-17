/*
    Ler um vetor R de 5 elementos contendo o gabarito da LOTO.
    A seguir ler um vetor A de 10 elementos contendo uma aposta.
    Por fim, imprima quantos pontos fez o apostador.

    Exemplo: R = 4 12 34 25 17 (gabarito);
             A = 3 17 55 21 34 4 27 29 20 11 (aposta);
             Saída: 3 pontos;
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetorR[5], aposta[10];
    int ponto = 0;
    int numero;
    int i = 0;
    int flag = 0;

    for (i = 0; i < 5; i++) // Gabarito
    {
        printf("Informe o numero do gabarito: ");
        scanf("%d", &vetorR[i]);
    }

    printf("\n");

    for (i = 0; i < 10; i++)
    {
        printf("Informe o numero da aposta: ");
        scanf("%d", &numero);

        for (int x = 0; x < 10; x++) // Compara se o numero informado ja esta no vetor de aposta.
        {
            if (numero == aposta[x])
            {
                flag = 1;
            }
        }

        if (flag == 1)
        {
            printf("Numero ja apostado.\n"); // Informa numero repetido e desconta -1 do i

            i -= 1;
            flag = 0;
        }
        else
        {
            aposta[i] = numero;

            for (int x = 0; x < 5; x++) // Verifica se o numero informado esta no vetor gabarito
            {
                if (aposta[i] == vetorR[x])
                {
                    ponto++;
                }
            }
        }
    }

    printf("\n");
    printf("Gabarito:\n");

    for (int i = 0; i < 5; i++) // Vetor gabarito.
    {
        printf("%d\n", vetorR[i]);
    }

    printf("\n");
    printf("Pontuacao: %d\n", ponto); // Pontuacao.

    system("pause");
    return 0;
}