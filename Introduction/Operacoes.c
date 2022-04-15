// Operadores matematicos basicos

#include <stdio.h>

int main()
{
    float NumeroA, NumeroB;
    float Result;

    printf("Digite um numero: "); // output de dados
    scanf("%f", &NumeroA);        // input de dados

    printf("Digite outro numero: ");
    scanf("%f", &NumeroB);
    printf("\n");

    Result = NumeroA + NumeroB;      // Soma
    printf("Soma: %0.0f\n", Result); // 0.n expressa a quantidades de casas depois da virgula.

    Result = NumeroA * NumeroB; // Multiplicacao
    printf("Multiplicacao: %0.0f\n", Result);

    Result = NumeroA - NumeroB; // Subtracao
    printf("Subtracao: %0.0f\n", Result);

    Result = NumeroA / NumeroB; // Divisao
    printf("Divisao: %0.2f\n", Result);

    return 0;
}