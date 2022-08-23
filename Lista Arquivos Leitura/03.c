/*
3. Faça um programa que permita que o usuário entre com diversos nomes
e telefone para cadastro, e crie um arquivo com essas informações, uma
por linha. O usuário finaliza a entrada com „0‟ para o telefone.
*/

#include <stdio.h>

int main()
{
    char nome[50];
    int telefone[12], resposta = 0;
    FILE *arquivo;
    arquivo = fopen("cadastro.txt", "w"); // abertura do arquivo
    if (arquivo == NULL)                  // testando abertura do arquivo
    {
        printf("Erro na abertura do arquivo.\n");
    }
    while (resposta == 0) // inserindo dados
    {
        printf("Informe o nome: ");
        fgets(nome, 50, stdin);
        fflush(stdin);
        printf("Informe o telefone: ");
        fgets(telefone, 12, stdin);
        fflush(stdin);
        fprintf(arquivo, "Nome: %s", nome); // inserindo dados no arquivo
        fprintf(arquivo, "Telefone: %s\n", telefone);
        printf("Continuar? [0/1]: ");
        scanf("%d", &resposta);
        fflush(stdin);
        printf("\n");
    }
    fclose(arquivo);
    return 0;
}