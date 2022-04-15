#include <stdio.h>
int main()
{
    float A;
    printf("Formatar variáveis reais: \n");
    A = 3456.78;
    printf("%4.2f\n", A);
    printf("%3.2f\n", A);
    printf("%3.1f\n", A);
    printf("%10.3f\n", A);
    return 0;
}
