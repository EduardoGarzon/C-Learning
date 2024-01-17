/*
    Arquivo de cabecalho (Header File).
    Fornecer a interface da classe, estrutura da classe.
    Prototipos dos métodos.
*/

/*
    Os comandos #ifndef, #define e #endif são diretivas de pré-processamento em C.

    Eles são usados para garantir que um determinado bloco de código seja incluído 
    no programa apenas uma vez, evitando problemas de duplicação de definições e redefinições.
*/
#ifndef PERSON_H
#define PERSON_H

// "Classe"
typedef struct
{
    char nome[50];
    int idade;
    
    void (*apresentar)(void *);
    void (*maioridade)(int);
    
    /*
        Essa declaração define um ponteiro para função chamado "apresentar"
        que não retorna valor (void) e recebe um ponteiro genérico (void *) como argumento.

        O objetivo de usar um ponteiro para função é permitir que você
        armazene o endereço de uma função em uma variável e,
        posteriormente, chame essa função através desse ponteiro.

        É uma forma flexível de referenciar 
        e invocar funções dinamicamente em tempo de execução.

        Para utilizar esse ponteiro para função,
        você precisará atribuir a ele o endereço de uma função compatível, ou seja,
        uma função que tenha o mesmo tipo de retorno e argumentos esperados.
    */
} Pessoa;

Pessoa *criarPessoa(const char *nome, int idade);
void destruirPessoa(Pessoa *pessoa);
void maioridade(const int idade);

#endif