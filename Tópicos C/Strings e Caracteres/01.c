/* Solicite ao usuário que informe uma palavra. O programa deve informar a existência de
uma letra dentro desta palavra. (a letra que será procurada é informada pelo usuário
também) 18/09/2022 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char palavra[20];
    char letra[0];
    int flag = 0;

    printf("Informe uma palavra: ");
    scanf("%s", palavra);

    printf("Informe uma letra: ");
    scanf("%s", &letra);

    for (int i = 0; i < 20; i++)
    {
        if (letra[0] == palavra[i])
        {
            flag++;
        }
    }

    if (flag >= 1)
    {
        printf("\nA letra informada foi encontrada no Vetor String!");
    }
    else
    {
        printf("\nA letra informada nao foi encontrada no vetor String!");
    }

    return 0;
}