/*
    Exercicio 03 - Calculando a gorjeta e dividindo uma conta de restaurante
    Ler o valor da despesa no restaurante, Ler o valor percentual da gorjeta
    Calcular a divisao igualitaria da despesa pelo total de individuos
*/

#include <stdio.h>

int main()
{
    float despesa, gorjeta, valor_individual;
    int pessoas;

    printf("Informe o valor gasto no restaurante: ");
    scanf("%f", &despesa);
    printf("Informe o percentual da gorgeta: ");
    scanf("%f", &gorjeta);
    printf("Informe o total de individuos: ");
    scanf("%d", &pessoas);
    printf("\n");

    despesa += ((gorjeta / 100) * despesa); // calculando a despesa
    valor_individual = despesa / pessoas;   // calculando o pagamento individual

    printf("Gasto total: %.2f\n", despesa);
    printf("Pagamento individual: %.2f\n", valor_individual);

    return 0;
}