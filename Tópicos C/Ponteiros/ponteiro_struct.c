/*
Exemplo de ponteiro para struct.
Toda variavel esta associada a uma regiao de memoria,
logo podemos criar ponteiros para variaveis struct.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int idade;
} Data;

Data data;
Data *p;

// Atribuindo valores a struct por ponteiro
void inserir_Idade(Data *p)
{
    printf("\n");
    printf("Informe a sua idade: ");
    scanf("%d", &p->idade);
    printf("\n");
}

void imprime_Struct(Data *p)
{
    printf("Idade: %d\n", p->idade);
}

int main()
{
    // atribuindo ao ponteiro o endereco da variavel struct.
    p = &data;

    printf("Endereco da variavel struct: %p\n", &data);
    printf("Conteudo do ponteiro struct: %p\n", p);

    inserir_Idade(p);
    // Apos a funcao com ponteiro struct
    imprime_Struct(p);
    // Original com variavel struct
    printf("Idade: %d\n", data.idade);

    system("pause");
    return 0;
}