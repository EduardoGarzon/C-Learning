#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura "Pessoa"
typedef struct
{
    char nome[50];
    int idade;
    void (*apresentar)(void *);
} Pessoa;

// Método "apresentar" da classe "Pessoa"
void apresentarPessoa(void *pessoaPtr)
{
    Pessoa *pessoa = (Pessoa *)pessoaPtr;
    
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d anos\n", pessoa->idade);
}

// Função para criar uma nova instância da classe "Pessoa"
Pessoa *criarPessoa(const char *nome, int idade)
{
    Pessoa *pessoa = (Pessoa *)malloc(sizeof(Pessoa));
    
    if (pessoa != NULL)
    {
        strncpy(pessoa->nome, nome, sizeof(pessoa->nome) - 1);
        pessoa->idade = idade;
        pessoa->apresentar = &apresentarPessoa;
    }

    return pessoa;
}

// Função para destruir uma instância da classe "Pessoa"
void destruirPessoa(Pessoa *pessoa)
{
    free(pessoa);
}

int main()
{
    // Criação de uma nova instância da classe "Pessoa"
    Pessoa *pessoa = criarPessoa("João", 25);

    // Chamada do método "apresentar" da classe "Pessoa"
    pessoa->apresentar(pessoa);

    // Destruir a instância da classe "Pessoa"
    destruirPessoa(pessoa);

    system("pause");
    return 0;
}
