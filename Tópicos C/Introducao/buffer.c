// O problema de usar scanf, getchar, getc e fgetc para receber caracteres em C

#include <stdio.h>
int main()
{
    char letra1;
    char letra2;

    printf("Informe uma letra: ");
    scanf("%c", &letra1);         // Na função scanf, dê um espaço entre a aspa " e o símbolo %c,
    printf("Informe uma letra: "); // espaço é um comando para o C desconsiderar o enter, tab ou espaço em branco.
    scanf(" %c", &letra2);          // só é possível fazer isso na scanf, enter também é uma tecla representada '\n'
    printf("Letra1: %c, Letra2: %c\n", letra1, letra2);

    // Se digitamos a letra 'C', que é armazenada na variável 'letra1' e em seguida apertamos enter.
    // Esse caractere (enter), ficará armazenado no buffer do teclado (um memória temporária).
    // Em seguida, noss programa em C pede para que algo seja armazenado na variável 'letra2'.
    // antes do C receber um novo dado do usuário,
    // ele checa se não tem mais alguma coisa armazenada no tecladolá tem um caractere enter.
    // Então o programa pega esse caractere e o coloca na variável letra2,
    // e é por isso que aparece uma quebra de linha em nosso programa.
    // uma alternativa, caso não queria usar o espaço entre " e o %c na scanf,
    // é limpar o buffer após cada scanf(), getchar(), getc() ou fgetc().
    // Para limpar o buffer em Windows, use : fflush(stdin)
    // Para limpar o buffer em Linux, use : __fpurge(stdin)
    fflush(stdin);
    printf("Informe uma letra: ");
    scanf("%c", &letra1);
    fflush(stdin);
    printf("Informe uma letra: ");
    scanf("%c", &letra2);
    printf("Letra1: %c, Letra2: %c", letra1, letra2);
    return 0;
}
