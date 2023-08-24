#include <stdio.h>

int main()
{
    int inteiro;    // Variavel de nome inteiro para armazenar valores inteiros
    float real;     // Variavel de nome fracionario para armazenas valores reais
    char caractere; // Variavel de nome caracteres para armazenar caracteres (letras)

    printf("Informe usa idade: ");
    scanf("%d", &inteiro);

    printf("Idade infomada: %d\n", inteiro);

    /*
        %d indica inteiro decimal
        %f indica float, real
        %c indica caractere, letras

        & (e comercial) indica obter o endereco de memoria da variavel que recebera o dado lido
    */

    // Lendo varios valores com scanf
    int valor1, valor2, valor3;

    printf("Informe 3 valores inteiros: ");
    scanf("%d%d%d", &valor1, &valor2, &valor3);

    printf("Valores informados: %d, %d, %d\n", valor1, valor2, valor3);

    return 0;
}