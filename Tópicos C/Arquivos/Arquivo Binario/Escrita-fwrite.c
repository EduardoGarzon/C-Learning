/*
    Exemplo de escrita em arquivo binario utilizando fwrite.

    Modos de abertura de arquivos:
        wb  -> Escrita
        rb  -> leitura
        ab  -> anexar
        rb+ -> leitura e escrita
        wb+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        ab+ -> leitura e escrita (adiciona ao final do arquivo)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int dia, mes, ano;
} Contato;

void escrever(char arq[])
{
    Contato c;
    FILE *file = fopen(arq, "ab");

    if (file)
    {
        printf("Digite o nome e a data de nascimento dd mm aaaa: ");
        scanf("%49[^\n]%d%d%d", c.nome, &c.dia, &c.mes, &c.ano);
        // Endereco da variavel, Tamanho do dado, Quantidade de dados e Ponteiro para o arquivo
        fwrite(&c, sizeof(Contato), 1, file);
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

int main()
{
    char arquivo[] = {"agenda.dat"};

    escrever(arquivo);

    /*
        // exemplos de uso da função fwrite

        // escreve 1 número inteiro no arquivo binário
        fwrite(&num, sizeof(int), 1, file);

        // escreve 5 números inteiros no arquivo binário
        fwrite(vet, sizeof(int), 5, file);

        // escreve um caracter no arquivo binário
        fwrite(&letra, sizeof(char), 1, file);

        // escreve um Contato no arquivo binário
        fwrite(&c, sizeof(Contato), 1, file);
    */

    return 0;
}