#include <stdio.h>
int main()
{
    int N = 2, M = 3;
    char Letra = 'a';
    float X = 2.5f;
    double Z = 3.5e-10;
    float media = 0, R = 2, T = 3;

    printf("----------Testando variáveis e tipos de dados ----------\n");
    printf("O primeiro valor impresso é uma constante decimal %d\n", 15);
    printf("Os valores das primeiras variáveis declaradas e inicializadas são %d, %d\n", N, M);
    printf("O valor da variável Letras declarada e inicializada é %c\n", Letra);
    printf("O valor da primeira variável de ponto flutuante (prec. Simples) é %f\n", X);
    printf("O valor da segunda variável de ponto flutuante (prec. Dupla) é %f\n", Z);
    printf("O valor da segunda variável de ponto flutuante (prec. Dupla) é %.11f\n", Z);
    printf("O valor da expressão que soma 4 ao valor de N é %d\n", N + 4);
    media = (N + M) / 2;
    printf("A média de duas variáveis inteiras N=%d e M=%d armazenando a média em uma variável real é %f\n", N, M, media);
    media = (T + R) / 2;
    printf("A média de duas variáveis reais T=%f e R=%f armazenando a média em uma variável real é %f\n", T, R, media);
    printf("As variáveis utilizadas (declaradas e inicializadas) foram N=%d, M=%d, \
Letra=%c, X=%f, Z=%.11f, media=%f, R=%f, T=%f\n",
           N, M, Letra, X, Z, media, R, T);
}
