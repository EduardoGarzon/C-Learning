#include <stdio.h>

int main()
{
    /*
        System("pause") é uma funcao do Windows

        Dependendo do compilador ou IDE utilizada para executar o código, pode ocorrer de o terminal permanecer aberto apenas durante a execucao do processo fechando logo em seguida
        impossibilitando avaliar a saida gerada pelo codigo.

        Assim, usa-se a funcao System("pause") para pausar o terminal, porem, o seu uso
        limita a portabilidade do codigo pois esta funcao é exclusiva do S.O Windows.

        O exemplo abaixo utilizando apenas funcoes da biblioteca padrao do C permite
        contornar o problema do terminal fechar logo após a execucao,
        basta apenas ler qualquer caractere do usuario no final do programa para finalizar.

    */

    // Código do programa

    // imprime uma mensagem
    printf("Pressione qualquer tecla para continuar.");

    // ler um caractere do teclado
    scanf("%c");
    // ou
    getchar();

    return 0;
}