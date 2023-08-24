/*
    Exemplo de leitura em arquivo binario C utilizando fread

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
        fwrite(&c, sizeof(Contato), 1, file);
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

void ler(char arq[])
{
    Contato c;
    FILE *file = fopen(arq, "rb");

    if (file)
    {
        while (!feof(file))
        {
            // Endereco da variavel destino, Tamanho do dado lido,
            // Quantidade de dados e Ponteiro para o arquivo.
            // Retorna a quantidade de dados lidos
            if (fread(&c, sizeof(Contato), 1, file))
                printf("\nNome: %s\nData: %d/%d/%d\n", c.nome, c.dia, c.mes, c.ano);
        }
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

int main()
{
    char arquivo[] = {"agenda.dat"};

    escrever(arquivo);
    ler(arquivo);

    return 0;
}