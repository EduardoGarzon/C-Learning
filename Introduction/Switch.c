// Media Aritmetica e Media Ponderada utilizando estrutura de selecao Switch e repeticao While

#include <stdio.h>

int main()
{
    int resposta, resposta2, peso1, peso2;
    float num, num2, media;

    resposta2 = 1;

    while (resposta2 == 1)
    {
        printf("[1] - Media \n");
        printf("[2] - Media Ponderada \n");
        printf("Opcao: ");
        scanf("%i", &resposta);
        switch (resposta)
        {
        case 1:
            printf("\nInforme a primeira nota: ");
            scanf("%f", &num);
            printf("Informe a segunda nota: ");
            scanf("%f", &num2);

            num += num2;
            media = num / 2;

            printf("Media: %g", media);
            break;

        case 2:
            printf("\nInforme a primeira nota: ");
            scanf("%f", &num);
            printf("Ïnforme o peso da primera nota: ");
            scanf("%i", &peso1);
            printf("Informe a segunda nota: ");
            scanf("%f", &num2);
            printf("Informe o peso da segunda nota: ");
            scanf("%i", &peso2);

            num *= peso1;
            num2 *= peso2;
            peso1 += peso2;
            media = (num + num2) / peso1;

            printf("Media Ponderada: %g", media);
            break;

        default:
            printf("\nInforme uma opcao valida. \n");
        }
        printf("\n\nContinuar? [1/0]: ");
        scanf("%i", &resposta2);
        printf("\n");
    }
}
