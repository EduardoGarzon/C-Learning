// #include é uma Diretiva de pré-processamento para carregar bibliotecas.
// stdio.h é uma biblioteca padrao do C que contem funcoes de entrada e saida.
#include <stdio.h>

// Funcao Principal do programa.
// Inicia aqui e segue um caminho top-down em sua execucao.
// Retorna um numero inteiro, 0 se programa executado sem erros e 1 caso existam erros.
int main()
{
    // Comentario em Linha.

    /*
        Comentario
        em
        Multiplas
        Linhas.
    */

    // ------------------------------------------------------------------------------------

    printf("-----------------------------------------------------------\n\n");
    // Funcao que imprime uma saida no terminal.
    printf("Hello World\n");
    printf("-----------------------------------------------------------\n\n");

    // ------------------------------------------------------------------------------------

    /*
        Escape Sequence = Combinacao de caracteres que consistem de uma
                          barra invertida seguinda por uma letra ou combinacao de digitos. Especificam acoes em uma linha ou uma string de texto.

                          \n = nova linha;
                          \t = tab ou tabulacao;
                          \" = Aspas Duplas
                          \\ = \
    */

    printf("\n\nPulando Linha\n");
    printf("Eu\nsou\num\ntexto.\n");
    printf("\n\n");

    printf("\tTAB\n");
    printf("1\t2\t3\n");
    printf("\n\n");

    printf("\"Ola\" - Pessoa Desconhecida.\n\n");

    printf("\\Barra\\\n");
    printf("\n\n");

    printf("-----------------------------------------------------------\n\n");

    // ------------------------------------------------------------------------------------

    // Variaveis sao espacos alocados em memoria para diferentes tipos de dados.

    int idade;   // declaracao de uma variavel do tipo inteiro chamada idade.
    idade = 22;  // inicializacao da variavel, atribuicao do valor 22.
    int y = 100; // Declaracao + Inicializacao.

    float altura = 1.70; // Variavel para valores com ponto flutuate, conjunto dos reais.

    char c = 'C';                 // Variavel que armazena apenas um caractere.
    char nome[] = "Luiz Eduardo"; // Array de caracteres, representa uma string de texto.

    printf("Minha altura e: %f\n", altura);
    printf("Minha idade e: %d\n", idade);
    printf("Meu nome e: %s\n", nome);
    printf("\n\n");

    printf("-----------------------------------------------------------\n\n");


    // A funcao retorna 0 para indicar a execucao bem sucedida do programa.
    return 0;
}