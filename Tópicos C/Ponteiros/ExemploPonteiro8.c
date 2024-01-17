/*
    Realizando multiplicacoes com ponteiros de ponteiros.
    
    O programa le a variavel A e 
    calcula o seu dobro(*B), triplo(**C) e quadruplo(***D)
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variavel do tipo inteiro
    int A = 10;
    // Ponteiro para inteiro
    int *B;
    // Ponteiro para Ponteiro de inteiro
    int **C;
    // Ponteiro para Ponteiro de Ponteiro de inteiro
    int ***D;

    // No final das contas todos apontam para a variavel A (D -> C -> B -> A)
    B = &A;
    C = &B;
    D = &C;

    printf("Dobro de A[%d]: B[%d]\n", A, 2 * *B);
    
    printf("Triplo de A[%d]: C[%d]\n", A, 3 * **C);
    
    printf("Quadruplo de A[%d]: D[%d]\n", A, 4 * ***D);

    system("pause");
    return 0;
}