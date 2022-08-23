/* 2. Solicite ao usuário que digite uma palavra e retorne quantas vogais existem nela. */

#include <stdio.h>
#include <string.h>

int main()
{
    char palavra[10];
    int flag = 0;

    printf("Escreva apenas uma palavra: ");
    fgets(palavra, 10, stdin);

    for (int i = 0; i < 10; i++)
    {
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u')
        {
            flag++;
        }
    }

    printf("\nTotal de vogais encontradas: %d", flag);
    return 0;
}