/*
    Solicite ao usuário a digitação de seu nome completo
    e informe quantos caracteres o mesmo contém.

    Faça essa contagem desconsiderando os espaços
    e sem a utilização de funções específicas.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[30]; // String do nome
    int flag = 0;  // int para contar os caracteres

    printf("Informe seu nome completo: ");
    fgets(nome, 30, stdin); // Leitura da String

    // incrementa enquanto nao achar o final da String
    for (int i = 0; nome[i] != '\0'; i++)
    {
        if (nome[i] != ' ') // incrementa a flag caso nao seja um caractere de espaco
        {
            flag++;
        }
    }

    printf("Seu nome possui %d caracteres.\n", flag - 1);

    system("pause");
    return 0;
}