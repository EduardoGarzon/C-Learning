/*
    Conversão de Base – B para 10
    (N)b = anan-1...a2a1a0,a-1a-2....a-k
    (N)10= anbn + an-1bn-1 + ... + a2b2 + a1b1 + a0b0 + a-1b-1 + a-2b-2 + ... + a-kb-k
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double numero = 0; // numero a ser convertido
    int inteiro = 0;   // parte inteira do numero
    double frac = 0;   // parte fracionaria do numero
    int fractoint = 0; // parte fracionaria trasnfromada em inteiro
    int algs = 0;

    int novo = 0; // valor obtido da conversao
    int vet[7];   // vetor para armazenar os algarismos
    int base = 0; // valor da base
    int i = 0;    // contador

    printf("Numero de algarismos depois da virgula: ");
    scanf("%d", &algs);
    printf("Informe um numero real: ");
    scanf("%lf", &numero);
    printf("Informe a base do numero: ");
    scanf("%d", &base);
    printf("\n");
    // separando parte inteira
    inteiro = ((int)numero);
    printf("Parte inteira: %d\n", inteiro);
    // separando parte fracionaria
    frac = numero - ((int)numero);
    printf("Parte fracionaria: %0.2f\n", frac);
    for (int x = 0; x < algs; x++)
    {
        frac = frac * 10;
    }
    printf("Parte fracionaria para inteira: %0.2f\n", frac);
    fractoint = frac;
    printf("Parte inteira float para int: %d\n", fractoint);

    // convertendo parte inteira
    while (inteiro > 0)
    {
        vet[i] = (inteiro % 10) * (pow(base, i)); // armazena cada algarismo de acordo com a formula
        inteiro = inteiro / 10;                   // pega o proximo algarismo
        novo += vet[i];                           // soma os algarismos calculados
        i++;
    }
    inteiro = novo;

    // convertendo parte fracionaria
    float result = 0;
    float resultfrac = 0;
    int exp = -1;
    while (fractoint > 0)
    {
        result = pow(base, exp);
        result = (fractoint % 10) * result;
        resultfrac += result;
        printf("Conversao fracionaira: %f \n", result);
        fractoint = fractoint / 10;
        exp--;
    }
    numero = inteiro + resultfrac;
    printf("\n");
    printf("================================================\n");
    printf("Parte inteira %d \n", inteiro);
    printf("Parte fracionaria %0.2f \n", resultfrac);
    printf("Conversao para base 10: %0.2f\n", numero);
    printf("================================================\n");

    return 0;
}