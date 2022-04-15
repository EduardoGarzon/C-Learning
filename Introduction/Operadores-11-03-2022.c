#include <stdio.h>
int main()
{
    int a = 15, b = 4, c;

    printf("Testando operadores aritméticos\n");
    printf("Valroes de a=%d, b=%d, c=%d\n", a, b, c);
    printf("Veja o conteudo de c sem feita sua inicialização! \n");
    a = c + a;
    printf("Soma aleatoria com C nao declarado: %d\n", a);
    c = a + b;
    printf("a+b = %d \n", c);
    c = a - b;
    printf("a-b = %d \n", c);
    c = a * b;
    printf("a*b = %d \n", c);
    c = a / b;
    printf("a/b = %d \n", c);
    c = a % b;
    printf("Resto da divisão de a por b = %d \n", c);

    return 0;
}
