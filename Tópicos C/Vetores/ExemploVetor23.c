/*
    Ler um vetor R de 10 elementos e um vetor S de 20 elementos.

    A seguir gere um vetor X que contenha uma única
    ocorrência dos elementos existentes em R ou em S (união).

    Após concluir o processamento escrever o vetor X.

    Considere que nos vetores R e S podem existir elementos repetidos.

    Exemplo:
    R= 7 4 4 5 7 2 1 3 4 6
    S= 12 4 4 8 27 12 11 31 42 61 5 2 9 9 1 2 17 9 2 19
    X= 7 4 5 2 1 3 6 12 8 27 11 31 42 61 9 17 19
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int R[10], S[20], X[30];
    int flag = 0;
    int y = 0;

    for (int i = 0; i <= 9; i++)
    {
        printf("Informe um numero para o Vetor R: ");
        scanf("%d", &R[i]);

        X[y] = R[i];
        y++;
    }

    printf("\n");

    for (int i = 0; i <= 19; i++)
    {
        printf("Informe um numero para o Vetor S: ");
        scanf("%d", &S[i]);

        for (int x = 0; x < y; x++)
        {
            if (S[i] == X[x])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            X[y] = S[i];
            y++;
        }

        flag = 0;
    }

    printf("\n");
    printf("Uniao dos elementos de R e S:\n");
    for (int i = 0; i < y; i++)
    {
        printf("%d ", X[i]);
    }

    system("pause");
    return 0;
}