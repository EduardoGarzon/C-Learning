// O problema de buffer utilizando o scanf para receber caracteres em C.

#include <stdio.h>
int main()
{
    char letra1;
    char letra2;

    /*
        Na função scanf, dê um espaço entre a aspa " e o símbolo %c.
        Espaço é um comando para o C desconsiderar o enter, tab ou espaço em branco.
        Só é possível fazer isso no scanf, enter também é uma tecla representada '\n'.
    */
    printf("Informe uma letra: ");
    scanf("%c", &letra1);
    printf("Informe uma letra: ");
    scanf(" %c", &letra2);
    printf("Letra1: %c, Letra2: %c\n", letra1, letra2);

    // Se digitamos a letra 'C', que é armazenada na variável 'letra1'
    // e em seguida apertamos enter, esse caractere (enter), ficará armazenado no buffer
    // do teclado (um memória temporária).

    // Em seguida, nosso programa em C pede para que algo seja armazenado na variável
    // 'letra2', antes dereceber um novo dado do usuário,
    // ele checa se não tem mais alguma coisa armazenada no teclado
    // e lá tem um caractere enter.
    // Então o programa pega esse caractere e o coloca na variável letra2,
    // e é por isso que aparece uma quebra de linha em nosso programa.

    // Uma alternativa, caso não queira usar o espaço entre " e o %c na scanf,
    // é limpar o buffer após cada scanf().
    // Para limpar o buffer em Windows, use : fflush(stdin)
    // Para limpar o buffer em Linux, use : __fpurge(stdin)

    fflush(stdin);
    printf("Informe uma letra: ");
    scanf("%c", &letra1);
    fflush(stdin);

    printf("Informe uma letra: ");
    scanf("%c", &letra2);

    printf("Letra1: %c, Letra2: %c\n", letra1, letra2);

    system("pause");
    return 0;
}
