#ifndef biblioteca_h
#define biblioteca_h

int soma(int a, int b, int c) // funcao que soma dois numeros inteiros informados pelo usuario
{
    c = a + b;
    return c;
}

int tamanho(char string[]) // funcao que conta a quantidade de caracteres de uma string
{
    int i = 0;
    int tamanho = 0;
    for (i = 0; string[i] != '\0'; i++)
    {
        tamanho = i;
    }
    return tamanho;
}
#endif