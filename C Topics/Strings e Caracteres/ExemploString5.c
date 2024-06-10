#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// funcao para calcular e retornar o tamanho da string
// tipo de retorno - identificador - parametros
int tamanho_String(char nome[])
{
    int tamanho = 0;

    // enquanto nao chegar no final da string e do \n incrementa o tamanho
    while (nome[tamanho] != '\0' && nome[tamanho] != '\n')
    {
        tamanho++;
    }

    return tamanho;
}

int main()
{
    char nome[100]; // vetor para o nome

    printf("Informe seu nome: ");
    fgets(nome, 100, stdin); // strlen conta \n
    //  gets(nome);             // strlen nao conta \n
    //  scanf("%s[^\n]", nome); // strlen nao conta \n mas só le o primeiro nome
    //  fflush(stdin);
    getchar();

    // conta espacos e \n
    printf("total de caracteres [funcao strlen]: %lld\n", strlen(nome) - 1);
    
    // conta espacos, nao conta \n
    printf("total de caracteres [minha strlen]: %d\n", tamanho_String(nome));

    system("pause");
    return 0;
}