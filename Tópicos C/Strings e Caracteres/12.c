/* 12. Faça um programa que solicite ao usuário a criação de um usuário e senha, pedindo para
que ele digite novamente a senha para comparar, em seguida retorne se foi validado ou
não. */

#include <stdio.h>
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
        printf("Informe uma senha [max - 10 caracteres] \n");
        gets(senha);

        if (strlen(user) > 10 || strlen(senha) > 10) // verifica se a senha e o usuario na excedem o total de caracteres permitidos
        {
            printf("\nNome ou senha maior do que o permitido, tente novamente!\n\n");
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

        for (int i = 0; i < strlen(senha); i++) // compara os dois vetores caractere a caractere
        {
            if (senha[i] == confirm[i]) // se forem iguais nos respectivos indices a flag é incrementada
            {
                flag++;
            }
        }

        if (strlen(senha) == flag) // senha valida se a flag for igual ao comprimento da senha
        {
            printf("\nSenha validada.");
        }
        else
        {
            printf("\nSenha invalidada, tente novamente.\n"); // senha invalida se a flag for diferente do comprimento, ou seja, algum caractere esta diferente
        }

    } while (strlen(senha) != flag);

    return 0;
}