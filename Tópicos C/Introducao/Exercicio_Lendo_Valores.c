#include <stdio.h>

int main()
{
    int idade;
    float altura, peso;
    char sexo;

    printf("Informe sua idade, altura, peso, sexo (M ou F) e incial do nome: ");
    scanf("%d%f%f %c", &idade, &altura, &peso, &sexo);

    /*
        O espaco antes do %c indica ao computador que ignore espacos, tabulacoes e ENTER
        para evitar problemas na leitura como 20\n1.72\n80\nM\n o \nM sera o conflito
        na leitura pois \n tambem é um caractere.

        Exemplo: lendo dois caracteres com scanf e limpando o buffer do teclado com espaco
        scanf("%c %c", &letra1, &letra2);

        outra forma de limpar o Buffer do teclado é ler o caractere sem salvar
        scanf("%c");
        e prosseguir com a leitura
    */

    printf("Idade: %d \nAltura: %.2f \nPeso: %.2f \nSexo: %c\n", idade, altura, peso, sexo);

    return 0;
}