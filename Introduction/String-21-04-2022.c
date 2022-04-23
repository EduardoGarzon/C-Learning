// Vetor String é um vetor de caracteres
// O ultimo elemento é \0, que sinaliza o final da palavra
// Preenchido da esquerda para a direita
// Os numeros perdem seu valor numerico
// funcao system("pause") - pausa o terminal para verificar a saída gerada pelo programa
// Para limpar o buffer em Windows, use: fflush(stdin)
// Para limpar o buffer em Linux, use: __fpurge(stdin)

#include <stdio.h>
#include <stdlib.h>

int main()
{

    char nome[10]; // Vetor com 9 espacos para caracteres
    char animal[10];
    char comida[10];

    printf("Informe uma comida, sem espacos: ");
    scanf(" %s", comida); // & não é obrigatório
    // o espaço antes do %s é um comando para o C desconsiderar o enter, tab ou espaço em branco somente no scanf

    printf("Informe um animal, sem espacos: ");
    scanf(" %s", animal); // %[] entre os colchetes inserimos os caracteres que desejamos utilizar para finalizar a digitacao

    fflush(stdin); // limpa o buffer do teclado, caractere armazenado em memoria temporaria
    printf("Informe seu nome: ");
    gets(nome); // realiza a leitura de palavras compostas, space-bar é entendido como caractere

    printf("\nnome: %s  | comida: %s | animal: %s", nome, comida, animal);

    return 0;
}