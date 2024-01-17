/*
    Exemplo de criacao, abertura e escrita com fputc em arquivo .txt em C

    Modos de abertura de arquivo em C:
        w  -> Escrita (cria o arquivo caso ele não exista e apaga todo seu conteudo caso exista)
        r  -> leitura
        a  -> anexar (adicionar informação ao final de um arquivo que já existe)
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;
    FILE *file; // ponteiro para o endereco do arquivo

    // nome do arquivo a ser aberto/criado e modo de abertura
    // a extensao do arquivo pode ser opcional, no nosso caso usamos .txt
    file = fopen("exemplo.txt", "w");

    if (file == NULL)
    {
        printf("\n");
        printf("Erro ao abrir arquivo!\n");
    }
    else
    {
        printf("Digite enter e pressione [ENTER] para finalizar!\n");
        scanf("%c", &letra);

        // enquanto nao for um \n ele le e insere no arquivo todas as letras do input
        while (letra != '\n')
        {
            fputc(letra, file);
            scanf("%c", &letra);
        }

        fclose(file); // fecha arquivo
    }

    system("pause");
    return 0;
}