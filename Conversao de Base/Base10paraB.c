/* Considere um número inteiro N na base 10 e a sua representação na base B denotada por: (ajaj-1...a2a1a0) B.
O algoritmo a seguir obtém acada k o dígito ak na base B sem a parte fracionaria. */

#include <stdio.h>

int main()
{
    int novo[7];        // novo numero na base B
    int voltas = 0;     // Voltas a cada passo
    int numero = 0;     // Numero Decimal
    int quociente = -1; // quociente
    int resto = 0;      // resto da divisao
    int base = 0;       // base para conversao

    printf("Informe o valor de N: ");
    scanf("%d", &numero);
    printf("Informe a base B para converao: ");
    scanf("%d", &base);

    while (quociente != 0)
    {
        if (base > numero) // verifica se o quociente é igual a zero
        {
            quociente = 0;
        }
        else
        {
            quociente = numero / base; // calculo do quociente caso nao for 0
        }
        resto = numero % base;                    // calculo do resto
        if (numero == (base * quociente) + resto) // calculo do numero decimal
        {
            voltas++;             // voltas do programa
            numero = quociente;   // numero recebe o quociente para proximo calculo
            novo[voltas] = resto; // o vetor do novo resutado armazena o resto
        }
    }

    for (int i = 0; i < voltas; i++)
    {
        printf("%d", novo[voltas - i]); // escrendo o vertor ao contrario para mostrar o resultado ascendente
    }

    return 0;
}