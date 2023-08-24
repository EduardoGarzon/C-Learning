/* 5. Faça uma função chamada primo que recebe como parâmetro um inteiro m e dois
outros inteiros p1 e p2 passados por referência. A função deve retornar em p1 o maior
número primo que é menor do que m e deve retornar em p2 o menor número primo que é
maior do que m. */

#include <stdio.h>

int primo(int *m, int *p1, int *p2) // parametros por referencia
{
    int flag = 0;
    int i = 0, c = 0;

    for (i = 1; i <= *m; i++) // Calcula o maior primo menor que M
    {
        for (c = 1; c <= i; c++)
        {
            if (i % c == 0)
            {
                flag++;
            }
        }
        if (flag == 2)
        {
            *p1 = i;
        }
        flag = 0;
    }
    for (i = *m; flag != 2; i++) // Calcula o menor primo maior que M
    {
        for (c = 1; c <= i; c++)
        {
            if (i % c == 0)
            {
                flag++;
            }
        }
        if (flag == 2)
        {
            *p2 = i;
        }
        else
        {
            flag = 0;
        }
    }

    printf("\nMaior primo menor que M: %d", *p1); // retorna os valores
    printf("\nMenor primo maior que M: %d", *p2);
}

int main()
{
    int m = 0, p1 = 0, p2 = 0;

    printf("Informe o valor de M: "); // leitura do valor
    scanf("%d", &m);

    primo(&m, &p1, &p2); // chamada da funcao por paramentros por referencia para calcular os primos

    return 0;
}