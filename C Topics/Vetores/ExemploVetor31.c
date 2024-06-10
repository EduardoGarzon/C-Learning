#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numbers[] = {1.0, 2.0, 3.0, 4.0, 5.0};

    // sizeof retorna o numero de bytes,
    // no caso temos 40 bytes ja que cada elemento tem 8 bytes.
    // entao basta dividir por qualquer elemento,
    // pois o tamanho de cada um em bytes é o mesmo e, assim,
    // teremos o tamanho total do array.

    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
    {
        printf("%f ", numbers[i]);
    }

    system("pause");
    return 0;
}