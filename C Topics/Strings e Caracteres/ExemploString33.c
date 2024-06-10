/*
    Faça um programa que padronize uma senha da seguinte forma:
        a. Conter no mínimo 8 caracteres;
        b. Conter letras;
        c. Conter números,;
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void chave(char senha[])
{
    int i, flag_letra = 0, flag_numero = 0, result = 0; // indice e flags de operacao

    while (result == 0)
    {
        if (strlen(senha) < 8) // testa a quantidade de caracteres minimos
        {
            printf("A senha deve conter no minimo 8 caracteres.\n");
        }
        else
        {
            result += 1; // result recebe +1 caso positivo
        }

        for (i = 0; i < strlen(senha); i++)
        {
            if (isalpha(senha[i]) != 0) // funcao que retorna se o caractere é uma letra
            {
                flag_letra++; // se for uma letra a flag e incrementada
            }
        }

        for (i = 0; i < strlen(senha); i++)
        {
            if (isdigit(senha[i]) != 0) // funcao que retornar se o caractere e um numero
            {
                flag_numero++; // se for um numero a flag e incrementada
            }
        }

        if (flag_letra == 0) // se a flag para letras for zero, indica a falta de letras
        {
            printf("A senha deve conter letras.\n");
        }
        else
        {
            result += 1; // result recebe +1 caso positivo
        }

        if (flag_numero == 0) // se a flag para numeros for zero, indica a falta de numeros
        {
            printf("A senha deve conter numeros.\n");
        }
        else
        {
            result += 1; // result recebe +1 caso positivo
        }
    }
    
    if (result == 3) // se result  = 3, indica que passou em todos os testes
    {
        printf("A senha informada e valida.\n");
    }
}

int main()
{
    char senha[30]; // string para a senha

    printf("Informe uma senha: ");
    fgets(senha, 30, stdin);

    chave(senha); // funcao que vai testar as regras definidas para a senha

    system("pause");
    return 0;
}