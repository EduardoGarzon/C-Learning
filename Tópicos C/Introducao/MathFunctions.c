// Exemplo de algumas funcoes matematicas.

#include <stdio.h>
#include <math.h>

int main()
{
    double A = sqrt(9);
    double B = pow(2, 4);

    int C = round(3.14);
    int D = ceil(3.14);
    int E = floor(3.99);

    double F = fabs(-100);
    double G = log(3);
    double H = sin(45);
    double I = cos(45);
    double J = tan(45);

    printf("Raiz Quadrada: %lf\n", A);
    printf("Potencia: %lf\n", B);
    printf("Arredondamento: %d\n", C);
    printf("Arredondamento Teto: %d\n", D);
    printf("Arredondamento Chao: %d\n", E);
    printf("Valor Absoluto: %lf\n", F);
    printf("Log: %lf\n", G);
    printf("Seno: %lf\n", H);
    printf("Cos: %lf\n", I);
    printf("Tang: %lf\n", J);

    system("pause");
    return 0;
}