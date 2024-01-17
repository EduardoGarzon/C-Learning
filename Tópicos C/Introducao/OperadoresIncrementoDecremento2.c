#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        Operador de Incremento:

        int contador = 1;

        contador++;
        contador += 1;
        contador = contador + 1;

        ++contador; incrementa o +1 antes da operacao
        contador++; incrementa o +1 depois da operacao

        Operador de decremento:

        int contador = 1;

        contador--;
        contador -= 1;
        contador = contador - 1;

        --contador; decrementa o -1 antes da operacao
        contador--; decrementa o -1 depois da operacao
    */

    int contador = 1;

    printf("Contador: %d\n", contador);
    printf("Contador++: %d\n", contador++);
    printf("Contador: %d\n", contador);
    printf("++contador: %d\n", ++contador);

    printf("\n");

    contador = 1;

    int resultado = contador++;
    printf("Resultado (contador++): %d\n", resultado);

    resultado = ++contador;
    printf("Resultado (++contador): %d\n", resultado);

    system("pause");
    return 0;
}