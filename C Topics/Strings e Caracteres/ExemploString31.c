/*
    Faça um programa que solicite ao usuário a criação de um usuário e senha,
    pedindo para que ele digite novamente a senha para comparar,
    em seguida retorne se foi validado ou não.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char user[10];    // string do usuario
    char senha[10];   // string da senha
    char confirm[10]; // string para confirmar senha
    int flag = 1;     // flag para contador

    while (flag == 1)
    {
        printf("Informe um nome de usuario [max - 10 caracteres] \n");
        gets(user);
        getchar();

        printf("Informe uma senha [max - 10 caracteres] \n");
        gets(senha);
        getchar();
        
        // verifica se a senha e o usuario na excedem o total de caracteres permitidos
        if (strlen(user) > 10 || strlen(senha) > 10)
        {
            printf("Nome ou senha maior do que o permitido, tente novamente!\n");
            flag = 1;
        }
        else if (strlen(user) <= 10 && strlen(senha) <= 10)
        {
            flag = 0;
        }
    }

    do
    {
        printf("Confirme sua senha: ");
        scanf("%s", confirm);
        getchar();

        // compara os dois vetores caractere a caractere
        for (int i = 0; i < (int)strlen(senha); i++)
        {
            // se forem iguais nos respectivos indices a flag é incrementada
            if (senha[i] == confirm[i])
            {
                flag++;
            }
        }

        // senha valida se a flag for igual ao comprimento da senha
        if (strlen(senha) == flag)
        {
            printf("Senha validada.\n");
        }
        else
        {
            // senha invalida se a flag for diferente do comprimento, 
            // ou seja, algum caractere esta diferente
            printf("Senha invalidada, tente novamente.\n");
        }

    } while (strlen(senha) != flag);

    system("pause");
    return 0;
}