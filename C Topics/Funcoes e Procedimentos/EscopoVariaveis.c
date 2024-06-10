/*
    Variaveis locais, globais e escopo de variaveis.

    Variavel local - declarada e manipulada somente na main,
    quando passada como parametro a funcao recebe uma copia de seu conteudo
    que é acessado em outro end de memoria e manipulado
    apenas dentro da funcao sem alterar a main.

    Variavel global - presente no corpo do programa, qualquer parte do programa pode ter acesso a essa variavel. Este tipo de variavel so é oculta e inacessivel quando algum procedimento ou funcao possui uma variavel local com o mesmo nome da variavel global.

    Escopo de variavel - onde exatamente cada variavel é visivel ou nao no programa.
    O escopo da variavel idade é a funcao main pois ela é uma var local que é visivel apenas para main. O escopo da variavel idade2 é global pois é visivel e acessivel para todo o programa.
*/

#include <stdio.h>
#include <stdlib.h>

int idade2 = 10; // variavel global

void incrementa_idade(int idade)
{
    idade++;  // alterada apenas dentro dessa funcao
    idade2++; // alterada pois é global
}

int main()
{
    int idade = 10;

    printf("idade: %d | idade2: %d\n", idade, idade2);
    incrementa_idade(idade);
    printf("idade: %d | idade2: %d\n", idade, idade2);

    system("pause");
    return 0;
}