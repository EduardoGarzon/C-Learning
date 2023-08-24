/*
6. Faça um programa que leia um vetor com os dados de 5 carros: marca (máximo 15
letras), ano e preço. Leia um valor p e mostre as informações de todos os carros
com preço menor que p. Repita este processo até que seja lido um valor p = 0.
*/

#include <stdio.h>

int main()
{
    float p = 0;
    struct carros
    {
        char marca[15];
        int ano;
        float preco;
    } carro[5];

    int i = 0;
    printf("Cadastro de carros: \n");
    for (i = 0; i < 5; i++)
    {
        printf("\nInforme a marca do carro: ");
        fgets(carro[i].marca, 15, stdin);
        fflush(stdin);
        printf("Informe o ano do carro: ");
        scanf("%d", &carro[i].ano);
        fflush(stdin);
        printf("Informe o preco do carro: ");
        scanf("%f", &carro[i].preco);
        fflush(stdin);
    }
    int flag = 0, resposta = 1;
    while (resposta == 1)
    {
        flag = 0;
        printf("\nInforme o preco desejado para o carro:");
        scanf("%f", &p);
        for (i = 0; i < 5; i++)
        {
            if (carro[i].preco <= p)
            {
                printf("\n");
                printf("Carro [%d]", i);
                printf("\nMarca: %s", carro[i].marca);
                printf("\nAno: %d", carro[i].ano);
                printf("\nPreco: %0.2f", carro[i].preco);
                flag++;
            }
        }
        if (flag == 0)
        {
            printf("\nNenhum carro detectado pelo abaixo do preco informado!\n");
        }
        printf("\nContinuar? [1 - sim / 0 - nao]: ");
        scanf("%d", &resposta);
        fflush(stdin);
    }

    return 0;
}