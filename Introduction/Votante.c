// Analisando atraves da idade a classificacao de votante do individuo

#include <stdio.h>

int main()
{
    int idade, resposta;
    resposta = 1;

    while (resposta == 1)
    {
        printf("Informe sua idade inteira: ");
        scanf("%i", &idade); // & armazena no endereco da variavel.
        printf("\n");

        if (idade >= 18 && idade <= 65)
        {
            printf("Usuario Votante. 18 - 65 ANOS");
        }
        else if (idade < 18 && idade >= 16)
        {
            printf("Voto opcional. 16 - 17 ANOS");
        }
        else
        {
            printf("Nao votante. Menor de 16 anos ou Maior de 65 anos.");
        }

        printf("\n");
        printf("Continuar? [Sim - 1 / Nao - 0]: ");
        scanf("%i", &resposta);
        printf("\n");
    }
}