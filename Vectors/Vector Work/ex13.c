/* 13. Ler um vetor VET de 5 elementos (cujos valores variam entre 5 no máximo até 15).
Gere um vetor FAT cujos componentes são os fatoriais dos respectivos elementos de VET.  */

#include <stdio.h>

int main()
{
    int vetor[5], vetorF[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Informe um valor entre 5 e 15: ");
        scanf("%d", &vetor[i]);

        for (int x = vetor[i]-1; x > 1; x--)
        {
            vetor[i] *= x;
        }
        vetorF[i] = vetor[i];
    }

    printf("\nVetor fatorial: \n");
    
    for (int i = 0; i < 5; i++)
    {
        printf("%i\n", vetorF[i]);
    }

    return 0;
}