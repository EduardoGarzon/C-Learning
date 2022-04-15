// String para resposta utilizando if else

#include <stdio.h>
#include <string.h> // strcmp == string compare

int main()
{
    char resposta[4];

    printf("Fabricio e uma gostosa? [sim / nao]: ");
    scanf("%s", &resposta);

    if (!strcmp(resposta, "sim"))
    {
        printf("Parabens, voce acertou.");
    }
    else
    {
        printf("Voce errou.");
    }
}

// strcmp retornar 0 se os valores forem iguais
// !strcmp valores diferentes