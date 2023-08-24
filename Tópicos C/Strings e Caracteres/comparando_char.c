#include <stdio.h>
#include <string.h>

int main()
{
    char letra1[2];
    char letra2[2];
    int resultado;

    printf("Informe uma letra: ");
    scanf("%s", letra1);
    fflush(stdin);
    printf("Informe outra letra: ");
    scanf("%s", letra2);

    /*
    Uma variável char é um valor integral de 8 bits, de 0 a 255. Aqui, 0 representa o carácter C-nulo, e 255 representa um símbolo vazio.
    Uma variável de caracteres tem o seu próprio valor ASCII. Assim, os caracteres são comparados de acordo com os valores ASCII.
    */
    if (letra1[0] > letra2[0])
    {
        printf("\n%s maior que %s", letra1, letra2);
    }
    else if (letra2[0] > letra1[0])
    {
        printf("\n%s maior que %s", letra2, letra1);
    }
    else if (letra1[0] == letra2[0])
    {
        printf("\n%s e %s sao iguais", letra1, letra2);
    }

    /* Se os primeiros caracteres das duas strings forem iguais, o próximo caractere das duas strings será comparado. Continua até que os caracteres correspondentes de ambas as strings sejam diferentes ou seja alcançado um carácter nulo '\0'.
    Se duas strings forem iguais ou idênticas, retorna 0.
    Se o valor ASCII do primeiro carácter for maior que o segundo, retorna um valor inteiro positivo
    Se o valor ASCII do primeiro carácter for inferior ao do segundo, devolve um valor inteiro negativo.
    */
    resultado = strcmp(letra1, letra2);
    printf("\nstrcmp(letra1, letra2) == %d", resultado);

    return 0;
}
