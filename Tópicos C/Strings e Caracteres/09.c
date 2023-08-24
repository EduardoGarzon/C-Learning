/* 9. Solicite ao usuário a digitação de seu nome completo e informe quantos caracteres o
mesmo contém. Faça essa contagem desconsiderando os espaços e sem a utilização de
funções específicas. */

#include <stdio.h>

int main()
{
    char nome[30]; // String do nome
    int flag = 0;  // int para contar os caracteres

    printf("Informe seu nome completo: ");
    fgets(nome, 30, stdin); // Leitura da String

    for (int i = 0; nome[i] != '\0'; i++) // incrementa enquanto nao achar o final da String
    {
        if (nome[i] != ' ') // incrementa a flag caso nao seja um caractere de espaco
        {
            flag++;
        }
    }

    printf("\nSeu nome possui %d caracteres.", flag - 1);

    return 0;
}