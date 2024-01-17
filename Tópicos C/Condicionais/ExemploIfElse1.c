// String para resposta utilizando if else

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcmp == string compare

int main()
{
    char resposta[4];

    printf("O sol é quente? [sim / nao]: ");
    scanf("%s", &resposta);

    // strcmp retornar 0 se os valores forem iguais
    // !strcmp valores diferentes
    if (!strcmp(resposta, "sim"))
    {
        printf("Parabens, voce acertou.");
    }
    else
    {
        printf("Voce errou.");
    }

    system("pause");
    return 0;
}
