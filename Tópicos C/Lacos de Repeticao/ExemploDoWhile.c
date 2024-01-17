// contador de um valor inicial ate um valor final utilizando do while.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int start, end;

    printf("Informe um numero inteiro positivo: ");
    scanf("%i", &start);
    
    printf("Informe outro numero inteiro positivo: ");
    scanf("%i", &end);

    do
    {
        printf("%i\n", start);
        start += 1;
    } while (start <= end);

    system("pause");
    return 0;
}