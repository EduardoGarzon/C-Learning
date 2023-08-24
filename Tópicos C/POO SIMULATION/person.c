/*
    Este é o arquivo de implementação da classe Person.h
    Aqui estão os detalhes de implementação dos métodos declarados no arquivo de cabeçalho.
    O arquivo de implementação é onde você escreve o código real dos métodos e realiza as operações desejadas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

void apresentarPessoa(void *pessoaPtr)
{
    Pessoa *pessoa = (Pessoa *)pessoaPtr;
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d anos\n", pessoa->idade);
}

Pessoa *criarPessoa(const char *nome, int idade)
{
    Pessoa *pessoa = (Pessoa *)malloc(sizeof(Pessoa));
    if (pessoa != NULL)
    {
        strncpy(pessoa->nome, nome, sizeof(pessoa->nome) - 1);
        pessoa->idade = idade;
        pessoa->apresentar = apresentarPessoa;
        pessoa->maioridade = maioridade;
        
    }
    return pessoa;
}

void destruirPessoa(Pessoa *pessoa)
{
    free(pessoa);
}

void maioridade(const int idade)
{
    if (idade >= 18)
        printf("Maior de Idade\n");
    else
        printf("Menor de Idade\n");
}