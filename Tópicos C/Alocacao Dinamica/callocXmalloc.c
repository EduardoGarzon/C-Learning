/*
    Calloc vs Malloc
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i, *vet1, *vet2;

    vet1 = malloc(10 * sizeof(int)); /*Inicializa com lixo de memoria*/
    vet2 = calloc(10, sizeof(int));  /*Inicializa zerado*/

    printf("\nCom malloc: ");
    for (i = 0; i < 10; i++)
        printf("%d ", vet1[i]);

    printf("\nCom calloc: ");
    for (i = 0; i < 10; i++)
        printf("%d ", vet2[i]);

    return 0;
}