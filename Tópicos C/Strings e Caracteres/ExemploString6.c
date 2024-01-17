/*
    1. Vetor String é um vetor de caracteres.
    2. O ultimo elemento é \0, que sinaliza o final da palavra.
    3. Preenchido da esquerda para a direita.
    4. Os numeros perdem seu valor numerico.
    5. Para limpar o buffer em Windows, use: fflush(stdin).
    6. Para limpar o buffer em Linux, use: __fpurge(stdin).
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    char nome[10]; // Vetor com 9 espacos para caracteres o ultimo é o \0
    char animal[10];
    char comida[10];

    printf("Informe uma comida, sem espacos: ");
    scanf(" %s", comida); // & não é obrigatório
    // o espaço antes do %s é um comando para o C desconsiderar o enter,
    // tab ou espaço em branco somente no scanf

    printf("Informe um animal, sem espacos: ");
    scanf("%s", animal);
    fflush(stdin); // limpa o buffer do teclado, caractere armazenado em memoria temporaria

    printf("Informe seu nome: ");
    gets(nome); // realiza a leitura de palavras compostas,
                // space-bar é entendido como caractere

    printf("nome: %s  | comida: %s | animal: %s\n", nome, comida, animal);

    system("pause");
    return 0;
}